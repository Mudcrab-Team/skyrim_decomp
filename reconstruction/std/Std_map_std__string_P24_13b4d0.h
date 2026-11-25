// Source exposure: binary-analysis
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of standard templates over stand-in element types
// Adapted bodies: none
// Std_map_std__string_P24_13b4d0: GUESS(low)
// P24: STANDIN GUESS(low); stand-in element struct of the stored size
#pragma once
#include <map>
#include <string>
#include <string.h>

struct P24 { void* p; int a, b; void* q; };
// order by object bytes so the struct can key a container without naming members
inline bool operator<(P24 const& l, P24 const& r) { return memcmp(&l, &r, sizeof(P24)) < 0; }
inline bool operator==(P24 const& l, P24 const& r) { return memcmp(&l, &r, sizeof(P24)) == 0; }

struct Std_map_std__string_P24_13b4d0 {};
