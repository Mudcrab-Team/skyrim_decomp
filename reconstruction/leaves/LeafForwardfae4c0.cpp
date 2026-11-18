// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfae4c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfae4c0 LeafForwardfae4c0::Forward
#include "LeafForwardfae4c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfae4c0::Forward() { return leaf_target(this); }
