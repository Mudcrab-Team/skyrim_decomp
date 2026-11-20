// Source exposure: binary-analysis; no external implementation reused.
// LeafForward4eba80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x4eba80 LeafForward4eba80::Forward
#include "LeafForward4eba80.h"
extern "C" void* leaf_target(void*);
void* LeafForward4eba80::Forward() { return leaf_target(this); }
