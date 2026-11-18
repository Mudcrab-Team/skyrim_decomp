// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb2900, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb2900 LeafForwardfb2900::Forward
#include "LeafForwardfb2900.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb2900::Forward() { return leaf_target(this); }
