// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfdfae0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfdfae0 LeafForwardfdfae0::Forward
#include "LeafForwardfdfae0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfdfae0::Forward() { return leaf_target(this); }
