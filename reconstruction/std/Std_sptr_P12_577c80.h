// Source exposure: binary-analysis
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of standard templates over stand-in element types
// Adapted bodies: none
// Std_sptr_P12_577c80: GUESS(low)
// P12: STANDIN GUESS(low); stand-in element struct of the stored size
#pragma once
#include <memory>
#include <string.h>

struct P12 { int a, b, c; };
// order by object bytes so the struct can key a container without naming members
inline bool operator<(P12 const& l, P12 const& r) { return memcmp(&l, &r, sizeof(P12)) < 0; }
inline bool operator==(P12 const& l, P12 const& r) { return memcmp(&l, &r, sizeof(P12)) == 0; }

struct Std_sptr_P12_577c80 {};
