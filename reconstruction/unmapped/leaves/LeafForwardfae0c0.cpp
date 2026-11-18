// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfae0c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfae0c0 LeafForwardfae0c0::Forward
#include "LeafForwardfae0c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfae0c0::Forward() { return leaf_target(this); }
