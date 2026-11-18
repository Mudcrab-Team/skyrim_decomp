// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardb068b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xb068b0 LeafForwardb068b0::Forward
#include "LeafForwardb068b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardb068b0::Forward() { return leaf_target(this); }
