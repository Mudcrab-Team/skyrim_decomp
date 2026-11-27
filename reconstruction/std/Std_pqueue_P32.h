// Source exposure: binary-analysis
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of standard templates over stand-in element types
// Adapted bodies: none
// Std_pqueue_P32: GUESS(low)
// P32: STANDIN GUESS(low); stand-in element struct of the stored size
#pragma once
#include <queue>
#include <string.h>

struct P32 { float a[8]; };
// order by object bytes so the struct can key a container without naming members
inline bool operator<(P32 const& l, P32 const& r) { return memcmp(&l, &r, sizeof(P32)) < 0; }
inline bool operator==(P32 const& l, P32 const& r) { return memcmp(&l, &r, sizeof(P32)) == 0; }

struct Std_pqueue_P32 {};
