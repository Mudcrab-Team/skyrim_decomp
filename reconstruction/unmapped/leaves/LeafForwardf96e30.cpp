// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf96e30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf96e30 LeafForwardf96e30::Forward
#include "LeafForwardf96e30.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf96e30::Forward() { return leaf_target(this); }
