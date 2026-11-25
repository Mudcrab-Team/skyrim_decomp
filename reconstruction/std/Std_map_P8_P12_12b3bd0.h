// Source exposure: binary-analysis
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of standard templates over stand-in element types
// Adapted bodies: none
// Std_map_P8_P12_12b3bd0: GUESS(low)
// P8, P12: STANDIN GUESS(low); stand-in element struct of the stored size
#pragma once
#include <map>
#include <string.h>

struct P8 { int a, b; };
// order by object bytes so the struct can key a container without naming members
inline bool operator<(P8 const& l, P8 const& r) { return memcmp(&l, &r, sizeof(P8)) < 0; }
inline bool operator==(P8 const& l, P8 const& r) { return memcmp(&l, &r, sizeof(P8)) == 0; }
struct P12 { int a, b, c; };
// order by object bytes so the struct can key a container without naming members
inline bool operator<(P12 const& l, P12 const& r) { return memcmp(&l, &r, sizeof(P12)) < 0; }
inline bool operator==(P12 const& l, P12 const& r) { return memcmp(&l, &r, sizeof(P12)) == 0; }

struct Std_map_P8_P12_12b3bd0 {};
