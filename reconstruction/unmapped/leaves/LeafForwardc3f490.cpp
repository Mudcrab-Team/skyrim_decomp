// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardc3f490, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xc3f490 LeafForwardc3f490::Forward
#include "LeafForwardc3f490.h"
extern "C" void* leaf_target(void*);
void* LeafForwardc3f490::Forward() { return leaf_target(this); }
