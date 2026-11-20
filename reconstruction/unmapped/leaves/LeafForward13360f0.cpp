// Source exposure: binary-analysis; no external implementation reused.
// LeafForward13360f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x13360f0 LeafForward13360f0::Forward
#include "LeafForward13360f0.h"
extern "C" void* leaf_target(void*);
void* LeafForward13360f0::Forward() { return leaf_target(this); }
