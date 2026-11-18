// Source exposure: binary-analysis; no external implementation reused.
// LeafForward36d730, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x36d730 LeafForward36d730::Forward
#include "LeafForward36d730.h"
extern "C" void* leaf_target(void*);
void* LeafForward36d730::Forward() { return leaf_target(this); }
