// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfae4e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfae4e0 LeafForwardfae4e0::Forward
#include "LeafForwardfae4e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfae4e0::Forward() { return leaf_target(this); }
