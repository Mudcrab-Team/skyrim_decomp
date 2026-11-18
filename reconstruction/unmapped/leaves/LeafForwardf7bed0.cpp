// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7bed0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7bed0 LeafForwardf7bed0::Forward
#include "LeafForwardf7bed0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7bed0::Forward() { return leaf_target(this); }
