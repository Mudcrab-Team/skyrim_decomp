// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing using standard library helper
// SPDX-License-Identifier: CC0-1.0
// 0x112830 Function112830
// Adapted bodies: none
#include <vector>
#include "FreeFunction_112830.h"

// Adjusts a manually vector-aligned allocation pointer and frees it with sized operator delete.
void Function112830(void* a_ptr, std::size_t a_bytes)
{
    std::_Adjust_manually_vector_aligned(a_ptr, a_bytes);
    ::operator delete(a_ptr, a_bytes);
}
