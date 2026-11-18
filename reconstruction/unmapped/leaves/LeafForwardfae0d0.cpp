// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfae0d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfae0d0 LeafForwardfae0d0::Forward
#include "LeafForwardfae0d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfae0d0::Forward() { return leaf_target(this); }
