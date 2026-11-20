// Source exposure: binary-analysis; no external implementation reused.
// LeafForward194170, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x194170 LeafForward194170::Forward
#include "LeafForward194170.h"
extern "C" void* leaf_target(void*);
void* LeafForward194170::Forward() { return leaf_target(this); }
