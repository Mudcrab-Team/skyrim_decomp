// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf76620, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf76620 LeafForwardf76620::Forward
#include "LeafForwardf76620.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf76620::Forward() { return leaf_target(this); }
