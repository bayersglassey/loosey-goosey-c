/*

    I downloaded this file from SQLite's downloads page:

        https://sqlite.org/download.html
        sqlite-src-3530400.zip
        Complete canonical source tree for SQLite version 3.53.4, include
        test cases and extensions.
        This is a snapshot of all code under version control at the time
        of release.
        This is the urtext.
        All of the other source code bundles shown below are derived from
        this one.

    ...and then I added doctests to it!
    - BAG, 2026

    >>> from loosey.mini import MiniC; mini = MiniC()
    >>> _ = mini.eval_file('examples/sqlite/hash.c')
    >>> _ = mini.eval_file('examples/sqlite/hash_mocks.c') # sqlite3Malloc, etc

    Create a fresh hash table:
    >>> mini.eval('Hash h; sqlite3HashInit(&h); pprint(h);')
      0x0: Struct:
      0x1:   'first': 0
      0x2:   'count': 0
      0x3:   'htsize': 0
      0x4:   'ht': 0

    Insert a couple of entries:
    >>> mini.eval('sqlite3HashInsert(&h, "key1", "hello")')
    0
    >>> mini.eval('sqlite3HashInsert(&h, "key2", "world")')
    0

    Inserting over an existing entry returns a pointer to the old data:
    >>> mini.eval('sqlite3HashInsert(&h, "key1", "bonjour")').as_c_string()
    b'hello'

    What's our hash table look like under the hood?..
    >>> mini.eval('pprint(h);')
      0x0: Struct:
      0x1:   'first': Pointer (offset=0) into memory:
      0x2:     0: Struct:
      0x3:       'pKey': Pointer (offset=0) into memory:
      0x4:         As a C string: b'key2'
      0x5:         0: 107
      0x6:         1: 101
      0x7:         2: 121
      0x8:         3: 50
      0x9:         4: 0
      0xa:       'h': 3723489572637945191932448255262090573131
      0xb:       'data': Pointer (offset=0) into memory:
      0xc:         As a C string: b'world'
      0xd:         0: 119
      0xe:         1: 111
      0xf:         2: 114
     0x10:         3: 108
     0x11:         4: 100
     0x12:         5: 0
     0x13:       'next': Pointer (offset=0) into memory:
     0x14:         0: Struct:
     0x15:           'pKey': Pointer (offset=0) into memory:
     0x16:             As a C string: b'key1'
     0x17:             0: 107
     0x18:             1: 101
     0x19:             2: 121
     0x1a:             3: 49
     0x1b:             4: 0
     0x1c:           'h': 3723489572637945191932448255259436137370
     0x1d:           'data': Pointer (offset=0) into memory:
     0x1e:             As a C string: b'bonjour'
     0x1f:             0: 98
     0x20:             1: 111
     0x21:             2: 110
     0x22:             3: 106
     0x23:             4: 111
     0x24:             5: 117
     0x25:             6: 114
     0x26:             7: 0
     0x27:           'next': 0
     0x28:           'prev': Pointer (offset=0) into memory at 0x1
     0x29:       'prev': 0
     0x2a:   'count': 2
     0x2b:   'htsize': 0
     0x2c:   'ht': 0

    Let's look up some entries!..
    >>> mini.eval('sqlite3HashFind(&h, "key1")').as_c_string()
    b'bonjour'
    >>> mini.eval('sqlite3HashFind(&h, "key2")').as_c_string()
    b'world'

    Looking up a missing entry returns a NULL pointer:
    >>> mini.eval('sqlite3HashFind(&h, "key3")')
    0

    And if we clear the table, its innards should be nice and clean:
    >>> mini.eval('sqlite3HashClear(&h); pprint(h);')
      0x0: Struct:
      0x1:   'first': 0
      0x2:   'count': 0
      0x3:   'htsize': 0
      0x4:   'ht': 0

    For fun, let's force some hash collisions!
    >>> mini.eval(r"""
    ...     // Add some entries using the original hash function
    ...     sqlite3HashInsert(&h, "x", 888);
    ...     sqlite3HashInsert(&h, "y", 999);
    ...
    ...     // Save the original hash function, then override it:
    ...     void originalStrHash = strHash;
    ...     int forcedHash = 100100;
    ...     static unsigned int strHash(const char *z){ return forcedHash; }
    ...
    ...     // Insert some entries, which should collide with each other
    ...     sqlite3HashInsert(&h, "BAM!", 10);
    ...     sqlite3HashInsert(&h, "BIFF", 20);
    ...     int forcedHash = 200200; // Insert some entries with a different hash
    ...     sqlite3HashInsert(&h, "BOOM", 30);
    ...     sqlite3HashInsert(&h, "CRAASH", 40);
    ...
    ...     // Restore the original hash function
    ...     strHash = originalStrHash;
    ... """)

    Now, what has happened is that our hash table now has some buckets,
    pointing into the doubly-linked list.
    The doubly-linked list still contains all the entries; the buckets
    just make it easy to jump quickly to the first list element which
    matches your hash:
    >>> mini.eval(r"""
    ...     printf("All entries:\n");
    ...     HashElem *entry;
    ...     for (entry = h.first; entry; entry = entry->next) {
    ...         printf("  Entry: key=\"%s\", hash=%i\n", entry->pKey, entry->h);
    ...     }
    ...
    ...     printf("The %i buckets and their first entries:\n", h.htsize);
    ...     int i;
    ...     for (i = 0; i < h.htsize; i++) {
    ...         struct _ht *bucket = h.ht[i];
    ...         if (!bucket->count) {
    ...             printf("  Bucket %i: Empty!\n", i);
    ...         } else {
    ...             printf("  Bucket %i: count=%i, first entry=(key=\"%s\", hash=%i)\n",
    ...                 i, bucket->count, bucket->chain->pKey, bucket->chain->h);
    ...         }
    ...     }
    ... """)
    All entries:
      Entry: key="CRAASH", hash=200200
      Entry: key="BOOM", hash=200200
      Entry: key="x", hash=233590346968
      Entry: key="y", hash=236244782729
      Entry: key="BAM!", hash=100100
      Entry: key="BIFF", hash=100100
    The 15 buckets and their first entries:
      Bucket 0: Empty!
      Bucket 1: Empty!
      Bucket 2: Empty!
      Bucket 3: Empty!
      Bucket 4: Empty!
      Bucket 5: count=2, first entry=(key="BAM!", hash=100100)
      Bucket 6: Empty!
      Bucket 7: Empty!
      Bucket 8: Empty!
      Bucket 9: Empty!
      Bucket 10: count=2, first entry=(key="CRAASH", hash=200200)
      Bucket 11: Empty!
      Bucket 12: Empty!
      Bucket 13: count=1, first entry=(key="x", hash=233590346968)
      Bucket 14: count=1, first entry=(key="y", hash=236244782729)

*/
/*
** 2001 September 22
**
** The author disclaims copyright to this source code.  In place of
** a legal notice, here is a blessing:
**
**    May you do good and not evil.
**    May you find forgiveness for yourself and forgive others.
**    May you share freely, never taking more than you give.
**
*************************************************************************
** This is the implementation of generic hash-tables
** used in SQLite.
*/
#include "hash.h"
#include <assert.h>

/* Turn bulk memory into a hash table object by initializing the
** fields of the Hash structure.
**
** "pNew" is a pointer to the hash table that is to be initialized.
*/
void sqlite3HashInit(Hash *pNew){
  assert( pNew!=0 );
  pNew->first = 0;
  pNew->count = 0;
  pNew->htsize = 0;
  pNew->ht = 0;
}

/* Remove all entries from a hash table.  Reclaim all memory.
** Call this routine to delete a hash table or to reset a hash table
** to the empty state.
*/
void sqlite3HashClear(Hash *pH){
  HashElem *elem;         /* For looping over all elements of the table */

  assert( pH!=0 );
  elem = pH->first;
  pH->first = 0;
  sqlite3_free(pH->ht);
  pH->ht = 0;
  pH->htsize = 0;
  while( elem ){
    HashElem *next_elem = elem->next;
    sqlite3_free(elem);
    elem = next_elem;
  }
  pH->count = 0;
}

/*
** The hashing function.
*/
static unsigned int strHash(const char *z){
  unsigned int h = 0;
  while( z[0] ){     /*OPTIMIZATION-IF-TRUE*/
    /* Knuth multiplicative hashing.  (Sorting & Searching, p. 510).
    ** 0x9e3779b1 is 2654435761 which is the closest prime number to
    ** (2**32)*golden_ratio, where golden_ratio = (sqrt(5) - 1)/2.
    **
    ** Only bits 0xdf for ASCII and bits 0xbf for EBCDIC each octet are
    ** hashed since the omitted bits determine the upper/lower case difference.
    */
#ifdef SQLITE_EBCDIC
    h += 0xbf & (unsigned char)*(z++);
#else
    h += 0xdf & (unsigned char)*(z++);
#endif
    h *= 0x9e3779b1;
  }
  return h;
}


/* Link pNew element into the hash table pH.  If pEntry!=0 then also
** insert pNew into the pEntry hash bucket.
*/
static void insertElement(
  Hash *pH,              /* The complete hash table */
  struct _ht *pEntry,    /* The entry into which pNew is inserted */
  HashElem *pNew         /* The element to be inserted */
){
  HashElem *pHead;       /* First element already in pEntry */
  if( pEntry ){
    pHead = pEntry->count ? pEntry->chain : 0;
    pEntry->count++;
    pEntry->chain = pNew;
  }else{
    pHead = 0;
  }
  if( pHead ){
    pNew->next = pHead;
    pNew->prev = pHead->prev;
    if( pHead->prev ){ pHead->prev->next = pNew; }
    else             { pH->first = pNew; }
    pHead->prev = pNew;
  }else{
    pNew->next = pH->first;
    if( pH->first ){ pH->first->prev = pNew; }
    pNew->prev = 0;
    pH->first = pNew;
  }
}


/* Resize the hash table so that it contains "new_size" buckets.
**
** The hash table might fail to resize if sqlite3_malloc() fails or
** if the new size is the same as the prior size.
** Return TRUE if the resize occurs and false if not.
*/
static int rehash(Hash *pH, unsigned int new_size){
  struct _ht *new_ht;            /* The new hash table */
  HashElem *elem, *next_elem;    /* For looping over existing elements */

#if SQLITE_MALLOC_SOFT_LIMIT>0
  if( new_size*sizeof(struct _ht)>SQLITE_MALLOC_SOFT_LIMIT ){
    new_size = SQLITE_MALLOC_SOFT_LIMIT/sizeof(struct _ht);
  }
  if( new_size==pH->htsize ) return 0;
#endif

  /* The inability to allocates space for a larger hash table is
  ** a performance hit but it is not a fatal error.  So mark the
  ** allocation as a benign. Use sqlite3Malloc()/memset(0) instead of
  ** sqlite3MallocZero() to make the allocation, as sqlite3MallocZero()
  ** only zeroes the requested number of bytes whereas this module will
  ** use the actual amount of space allocated for the hash table (which
  ** may be larger than the requested amount).
  */
  sqlite3BeginBenignMalloc();
  new_ht = (struct _ht *)sqlite3Malloc( new_size*sizeof(struct _ht) );
  sqlite3EndBenignMalloc();

  if( new_ht==0 ) return 0;
  sqlite3_free(pH->ht);
  pH->ht = new_ht;
  pH->htsize = new_size = sqlite3MallocSize(new_ht)/sizeof(struct _ht);
  memset(new_ht, 0, new_size*sizeof(struct _ht));
  for(elem=pH->first, pH->first=0; elem; elem = next_elem){
    next_elem = elem->next;
    insertElement(pH, &new_ht[elem->h % new_size], elem);
  }
  return 1;
}

/* This function (for internal use only) locates an element in an
** hash table that matches the given key.  If no element is found,
** a pointer to a static null element with HashElem.data==0 is returned.
** If pH is not NULL, then the hash for this key is written to *pH.
*/
static HashElem *findElementWithHash(
  const Hash *pH,     /* The pH to be searched */
  const char *pKey,   /* The key we are searching for */
  unsigned int *pHash /* Write the hash value here */
){
  HashElem *elem;                /* Used to loop thru the element list */
  unsigned int count;            /* Number of elements left to test */
  unsigned int h;                /* The computed hash */
  static HashElem nullElement = { 0, 0, 0, 0, 0 };

  h = strHash(pKey);
  if( pH->ht ){   /*OPTIMIZATION-IF-TRUE*/
    struct _ht *pEntry;
    pEntry = &pH->ht[h % pH->htsize];
    elem = pEntry->chain;
    count = pEntry->count;
  }else{
    elem = pH->first;
    count = pH->count;
  }
  if( pHash ) *pHash = h;
  while( count ){
    assert( elem!=0 );
    if( h==elem->h && sqlite3StrICmp(elem->pKey,pKey)==0 ){
      return elem;
    }
    elem = elem->next;
    count--;
  }
  return &nullElement;
}

/* Remove a single entry from the hash table given a pointer to that
** element and a hash on the element's key.
*/
static void removeElement(
  Hash *pH,         /* The pH containing "elem" */
  HashElem *elem    /* The element to be removed from the pH */
){
  struct _ht *pEntry;
  if( elem->prev ){
    elem->prev->next = elem->next;
  }else{
    pH->first = elem->next;
  }
  if( elem->next ){
    elem->next->prev = elem->prev;
  }
  if( pH->ht ){
    pEntry = &pH->ht[elem->h % pH->htsize];
    if( pEntry->chain==elem ){
      pEntry->chain = elem->next;
    }
    assert( pEntry->count>0 );
    pEntry->count--;
  }
  sqlite3_free( elem );
  pH->count--;
  if( pH->count==0 ){
    assert( pH->first==0 );
    assert( pH->count==0 );
    sqlite3HashClear(pH);
  }
}

/* Attempt to locate an element of the hash table pH with a key
** that matches pKey.  Return the data for this element if it is
** found, or NULL if there is no match.
*/
void *sqlite3HashFind(const Hash *pH, const char *pKey){
  assert( pH!=0 );
  assert( pKey!=0 );
  return findElementWithHash(pH, pKey, 0)->data;
}

/* Insert an element into the hash table pH.  The key is pKey
** and the data is "data".
**
** If no element exists with a matching key, then a new
** element is created and NULL is returned.
**
** If another element already exists with the same key, then the
** new data replaces the old data and the old data is returned.
** The key is not copied in this instance.  If a malloc fails, then
** the new data is returned and the hash table is unchanged.
**
** If the "data" parameter to this function is NULL, then the
** element corresponding to "key" is removed from the hash table.
*/
void *sqlite3HashInsert(Hash *pH, const char *pKey, void *data){
  unsigned int h;       /* the hash of the key modulo hash table size */
  HashElem *elem;       /* Used to loop thru the element list */
  HashElem *new_elem;   /* New element added to the pH */

  assert( pH!=0 );
  assert( pKey!=0 );
  elem = findElementWithHash(pH,pKey,&h);
  if( elem->data ){
    void *old_data = elem->data;
    if( data==0 ){
      removeElement(pH,elem);
    }else{
      elem->data = data;
      elem->pKey = pKey;
    }
    return old_data;
  }
  if( data==0 ) return 0;
  new_elem = (HashElem*)sqlite3Malloc( sizeof(HashElem) );
  if( new_elem==0 ) return data;
  new_elem->pKey = pKey;
  new_elem->h = h;
  new_elem->data = data;
  pH->count++;
  if( pH->count>=5 && pH->count > 2*pH->htsize ){
    rehash(pH, pH->count*3);
  }
  insertElement(pH, pH->ht ? &pH->ht[new_elem->h % pH->htsize] : 0, new_elem);
  return 0;
}
