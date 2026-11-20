// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf6a200, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf6a200 LeafForwardf6a200::Forward
#include "LeafForwardf6a200.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf6a200::Forward() { return leaf_target(this); }
