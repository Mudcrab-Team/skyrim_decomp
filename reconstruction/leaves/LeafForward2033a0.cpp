// Source exposure: binary-analysis; no external implementation reused.
// LeafForward2033a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x2033a0 LeafForward2033a0::Forward
#include "LeafForward2033a0.h"
extern "C" void* leaf_target(void*);
void* LeafForward2033a0::Forward() { return leaf_target(this); }
