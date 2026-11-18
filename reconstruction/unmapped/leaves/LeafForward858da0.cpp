// Source exposure: binary-analysis; no external implementation reused.
// LeafForward858da0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x858da0 LeafForward858da0::Forward
#include "LeafForward858da0.h"
extern "C" void* leaf_target(void*);
void* LeafForward858da0::Forward() { return leaf_target(this); }
