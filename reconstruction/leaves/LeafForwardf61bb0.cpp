// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf61bb0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf61bb0 LeafForwardf61bb0::Forward
#include "LeafForwardf61bb0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf61bb0::Forward() { return leaf_target(this); }
