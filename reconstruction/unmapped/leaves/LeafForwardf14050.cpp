// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf14050, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf14050 LeafForwardf14050::Forward
#include "LeafForwardf14050.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf14050::Forward() { return leaf_target(this); }
