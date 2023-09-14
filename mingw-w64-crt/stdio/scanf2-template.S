/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#if defined(_ARM_) || defined(__arm__)
        .thumb
#endif
        .text
        .p2align 4,,15
        .globl  FCT
        .def    FCT;    .scl    2;      .type   32;     .endef
#if defined(__x86_64__) && !defined(__arm64ec__)
        .seh_proc       FCT
#endif
FCT:
#if defined(__x86_64__) && !defined(__arm64ec__)
        .seh_endprologue
#endif
#if (defined(_AMD64_) && !defined(_ARM64EC_)) || (defined(__x86_64__) && !defined(__arm64ec__)) || defined(_X86_) || defined(__i386__)
        jmp     FWD
#elif defined(_ARM_) || defined(__arm__)
        .thumb_func
        b       FWD
#elif defined(_ARM64_) || defined(__aarch64__) || defined(_ARM64EC_) || defined(__arm64ec__)
        b       FWD
#endif
#if defined(__x86_64__) && !defined(__arm64ec__)
        .seh_endproc
#endif
        .def    FWD;  .scl    2;      .type   32;     .endef
