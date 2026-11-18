// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7aa10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7aa10 LeafForwardf7aa10::Forward
#include "LeafForwardf7aa10.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7aa10::Forward() { return leaf_target(this); }
