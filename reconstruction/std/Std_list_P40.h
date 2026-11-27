// Source exposure: binary-analysis
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of standard templates over stand-in element types
// Adapted bodies: none
// Std_list_P40: GUESS(low)
// P40: STANDIN GUESS(low); stand-in element struct of the stored size
#pragma once
#include <list>
#include <string.h>

struct P40 { void* p[5]; };
// order by object bytes so the struct can key a container without naming members
inline bool operator<(P40 const& l, P40 const& r) { return memcmp(&l, &r, sizeof(P40)) < 0; }
inline bool operator==(P40 const& l, P40 const& r) { return memcmp(&l, &r, sizeof(P40)) == 0; }

struct Std_list_P40 {};
