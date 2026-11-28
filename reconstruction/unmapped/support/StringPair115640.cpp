// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::allocator<Pair>::destroy
// SPDX-License-Identifier: CC0-1.0
// 0x115640 std::allocator<StringPair115640>::destroy
// Adapted bodies: none.
#include "StringPair115640.h"

template void std::allocator<StringPair115640>::destroy<StringPair115640>(StringPair115640* const);
