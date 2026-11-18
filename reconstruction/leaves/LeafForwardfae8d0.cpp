// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfae8d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfae8d0 LeafForwardfae8d0::Forward
#include "LeafForwardfae8d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfae8d0::Forward() { return leaf_target(this); }
