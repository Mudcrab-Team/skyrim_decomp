// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf97f10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf97f10 LeafForwardf97f10::Forward
#include "LeafForwardf97f10.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf97f10::Forward() { return leaf_target(this); }
