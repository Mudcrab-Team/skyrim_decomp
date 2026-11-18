// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1ed80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1ed80 LeafForwardf1ed80::Forward
#include "LeafForwardf1ed80.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1ed80::Forward() { return leaf_target(this); }
