// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf6ce30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf6ce30 LeafForwardf6ce30::Forward
#include "LeafForwardf6ce30.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf6ce30::Forward() { return leaf_target(this); }
