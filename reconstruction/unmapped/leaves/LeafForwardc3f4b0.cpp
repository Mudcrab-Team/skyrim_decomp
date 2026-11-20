// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardc3f4b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xc3f4b0 LeafForwardc3f4b0::Forward
#include "LeafForwardc3f4b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardc3f4b0::Forward() { return leaf_target(this); }
