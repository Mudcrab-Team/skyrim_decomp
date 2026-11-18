// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfae8f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfae8f0 LeafForwardfae8f0::Forward
#include "LeafForwardfae8f0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfae8f0::Forward() { return leaf_target(this); }
