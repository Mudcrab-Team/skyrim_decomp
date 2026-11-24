// x64 compatibility shim for sibling sources (force-included): CRT declarations the units used to
// declare themselves are removed by mkshadow.sh, so the standard headers supply them here. The
// 32-bit TLS read has no x64 equivalent and only feeds code whose shape is not compared.
#include <stddef.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <math.h>
#define __readfsdword(offset) 0UL
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
