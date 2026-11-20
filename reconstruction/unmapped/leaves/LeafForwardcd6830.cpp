// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardcd6830, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xcd6830 LeafForwardcd6830::Forward
#include "LeafForwardcd6830.h"
extern "C" void* leaf_target(void*);
void* LeafForwardcd6830::Forward() { return leaf_target(this); }
