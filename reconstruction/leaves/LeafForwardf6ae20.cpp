// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf6ae20, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf6ae20 LeafForwardf6ae20::Forward
#include "LeafForwardf6ae20.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf6ae20::Forward() { return leaf_target(this); }
