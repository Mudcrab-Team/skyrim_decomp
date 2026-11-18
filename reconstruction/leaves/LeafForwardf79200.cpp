// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf79200, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf79200 LeafForwardf79200::Forward
#include "LeafForwardf79200.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf79200::Forward() { return leaf_target(this); }
