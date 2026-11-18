// Source exposure: binary-analysis; no external implementation reused.
// LeafForward73a8a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x73a8a0 LeafForward73a8a0::Forward
#include "LeafForward73a8a0.h"
extern "C" void* leaf_target(void*);
void* LeafForward73a8a0::Forward() { return leaf_target(this); }
