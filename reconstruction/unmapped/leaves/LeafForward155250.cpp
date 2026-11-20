// Source exposure: binary-analysis; no external implementation reused.
// LeafForward155250, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x155250 LeafForward155250::Forward
#include "LeafForward155250.h"
extern "C" void* leaf_target(void*);
void* LeafForward155250::Forward() { return leaf_target(this); }
