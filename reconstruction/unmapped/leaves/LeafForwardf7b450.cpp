// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7b450, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7b450 LeafForwardf7b450::Forward
#include "LeafForwardf7b450.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7b450::Forward() { return leaf_target(this); }
