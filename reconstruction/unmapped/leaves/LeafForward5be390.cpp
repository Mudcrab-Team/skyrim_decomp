// Source exposure: binary-analysis; no external implementation reused.
// LeafForward5be390, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x5be390 LeafForward5be390::Forward
#include "LeafForward5be390.h"
extern "C" void* leaf_target(void*);
void* LeafForward5be390::Forward() { return leaf_target(this); }
