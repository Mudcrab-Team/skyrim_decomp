// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10c1630, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10c1630 LeafForward10c1630::Forward
#include "LeafForward10c1630.h"
extern "C" void* leaf_target(void*);
void* LeafForward10c1630::Forward() { return leaf_target(this); }
