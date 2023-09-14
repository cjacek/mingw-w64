/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#define __CRT__NO_INLINE
#include <math.h>

int __fpclassifyl (long double _x){
#if (defined(_AMD64_) && !defined(_ARM64EC_)) || (defined(__x86_64__) && !defined(__arm64ec__))
    __mingw_ldbl_type_t hlp;
    unsigned int e;
    hlp.x = _x;
    e = hlp.lh.sign_exponent & 0x7fff;
    if (!e)
      {
        unsigned int h = hlp.lh.high;
        if (!(hlp.lh.low | h))
          return FP_ZERO;
        else if (!(h & 0x80000000))
          return FP_SUBNORMAL;
      }
    else if (e == 0x7fff)
      return (((hlp.lh.high & 0x7fffffff) | hlp.lh.low) == 0 ?
	      FP_INFINITE : FP_NAN);
    return FP_NORMAL;
#elif defined(__arm__) || defined(_ARM_) || defined(__aarch64__) || defined(_ARM64_) || \
    defined(__arm64ec__) || defined(_ARM64EC_)
    return __fpclassify(_x);
#elif defined(__i386__) || defined(_X86_)
  unsigned short sw;
  __asm__ __volatile__ (
	"fxam; fstsw %%ax;"
	: "=a" (sw)
	: "t" (_x)
	);
  return sw & (FP_NAN | FP_NORMAL | FP_ZERO );
#endif
}
