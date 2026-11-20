// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf97c10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf97c10 LeafForwardf97c10::Forward
#include "LeafForwardf97c10.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf97c10::Forward() { return leaf_target(this); }
