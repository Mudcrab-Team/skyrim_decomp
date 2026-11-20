// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf6ce10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf6ce10 LeafForwardf6ce10::Forward
#include "LeafForwardf6ce10.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf6ce10::Forward() { return leaf_target(this); }
