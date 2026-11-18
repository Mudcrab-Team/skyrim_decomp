// Source exposure: binary-analysis; no external implementation reused.
// LeafForward13907a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x13907a0 LeafForward13907a0::Forward
#include "LeafForward13907a0.h"
extern "C" void* leaf_target(void*);
void* LeafForward13907a0::Forward() { return leaf_target(this); }
