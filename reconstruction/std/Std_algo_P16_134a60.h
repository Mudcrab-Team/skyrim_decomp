// Source exposure: binary-analysis
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of standard templates over stand-in element types
// Adapted bodies: none
// Std_algo_P16_134a60: GUESS(low)
// P16: STANDIN GUESS(low); stand-in element struct of the stored size
#pragma once
#include <algorithm>
#include <cstddef>
#include <utility>
#include <string.h>

struct P16 { float a, b, c, d; };
// order by object bytes so the struct can key a container without naming members
inline bool operator<(P16 const& l, P16 const& r) { return memcmp(&l, &r, sizeof(P16)) < 0; }
inline bool operator==(P16 const& l, P16 const& r) { return memcmp(&l, &r, sizeof(P16)) == 0; }

struct Std_algo_P16_134a60 {};
