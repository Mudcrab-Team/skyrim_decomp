// Source exposure: binary-analysis; no external implementation reused.
// LeafForward83d9e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x83d9e0 LeafForward83d9e0::Forward
#include "LeafForward83d9e0.h"
extern "C" void* leaf_target(void*);
void* LeafForward83d9e0::Forward() { return leaf_target(this); }
