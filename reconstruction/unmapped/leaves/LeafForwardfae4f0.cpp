// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfae4f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfae4f0 LeafForwardfae4f0::Forward
#include "LeafForwardfae4f0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfae4f0::Forward() { return leaf_target(this); }
