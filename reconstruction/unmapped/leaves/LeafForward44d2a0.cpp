// Source exposure: binary-analysis; no external implementation reused.
// LeafForward44d2a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x44d2a0 LeafForward44d2a0::Forward
#include "LeafForward44d2a0.h"
extern "C" void* leaf_target(void*);
void* LeafForward44d2a0::Forward() { return leaf_target(this); }
