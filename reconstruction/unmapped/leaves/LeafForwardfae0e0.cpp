// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfae0e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfae0e0 LeafForwardfae0e0::Forward
#include "LeafForwardfae0e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfae0e0::Forward() { return leaf_target(this); }
