// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb5600, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb5600 LeafForwardfb5600::Forward
#include "LeafForwardfb5600.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb5600::Forward() { return leaf_target(this); }
