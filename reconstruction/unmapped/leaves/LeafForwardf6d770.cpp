// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf6d770, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf6d770 LeafForwardf6d770::Forward
#include "LeafForwardf6d770.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf6d770::Forward() { return leaf_target(this); }
