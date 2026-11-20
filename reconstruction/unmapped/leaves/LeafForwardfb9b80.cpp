// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb9b80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb9b80 LeafForwardfb9b80::Forward
#include "LeafForwardfb9b80.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb9b80::Forward() { return leaf_target(this); }
