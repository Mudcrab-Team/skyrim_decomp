// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardcfa380, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xcfa380 LeafForwardcfa380::Forward
#include "LeafForwardcfa380.h"
extern "C" void* leaf_target(void*);
void* LeafForwardcfa380::Forward() { return leaf_target(this); }
