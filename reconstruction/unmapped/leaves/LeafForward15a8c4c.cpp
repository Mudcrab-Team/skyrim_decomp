// Source exposure: binary-analysis; no external implementation reused.
// LeafForward15a8c4c, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x15a8c4c LeafForward15a8c4c::Forward
#include "LeafForward15a8c4c.h"
extern "C" void* leaf_target(void*);
void* LeafForward15a8c4c::Forward() { return leaf_target(this); }
