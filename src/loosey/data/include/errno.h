#ifndef __LOOSEY_ERRNO__
#define __LOOSEY_ERRNO__

#define errno (__loosey_errno__())

// Magic token which causes preprocessor to define ENOMEM etc as macros
__LOOSEY_DEFINE_ERRCODES__

#endif
