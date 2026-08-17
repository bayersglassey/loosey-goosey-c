#ifndef __LOOSEY_CTYPE__
#define __LOOSEY_CTYPE__

static int isalnum(char c) { return isalpha(c) || isdigit(c); }
static int isalpha(char c) { return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'; }
static int isascii(char c) { return c <= 127; }
static int isblank(char c) { return c == ' ' || c == '\t'; }
static int iscntrl(char c) { return c < ' ' || c == 127; }
static int isdigit(char c) { return c >= '0' && c <= '9'; }
static int isgraph(char c) { return c > ' ' && c < 127; }
static int islower(char c) { return c >= 'a' && c <= 'z'; }
static int isprint(char c) { return c >= ' ' && c < 127; }
static int ispunct(char c) { return isgraph(c) && !isalnum(c); }
static int isspace(char c) { return c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v'; }
static int isupper(char c) { return c >= 'A' && c <= 'Z'; }
static int isxdigit(char c) { return c >= '0' && c <= '9' || c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F'; }

#endif
