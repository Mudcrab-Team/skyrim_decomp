// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8d54f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8d54f0 LeafForward8d54f0::Forward
#include "LeafForward8d54f0.h"
extern "C" void* leaf_target(void*);
void* LeafForward8d54f0::Forward() { return leaf_target(this); }
