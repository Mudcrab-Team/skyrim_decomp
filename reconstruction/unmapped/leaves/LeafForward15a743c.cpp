// Source exposure: binary-analysis; no external implementation reused.
// LeafForward15a743c, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x15a743c LeafForward15a743c::Forward
#include "LeafForward15a743c.h"
extern "C" void* leaf_target(void*);
void* LeafForward15a743c::Forward() { return leaf_target(this); }
