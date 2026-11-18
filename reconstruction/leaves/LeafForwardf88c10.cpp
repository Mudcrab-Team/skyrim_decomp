// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf88c10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf88c10 LeafForwardf88c10::Forward
#include "LeafForwardf88c10.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf88c10::Forward() { return leaf_target(this); }
