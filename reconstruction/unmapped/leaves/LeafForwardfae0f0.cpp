// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfae0f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfae0f0 LeafForwardfae0f0::Forward
#include "LeafForwardfae0f0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfae0f0::Forward() { return leaf_target(this); }
