// Source exposure: binary-analysis; no external implementation reused.
// LeafForward4f7910, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x4f7910 LeafForward4f7910::Forward
#include "LeafForward4f7910.h"
extern "C" void* leaf_target(void*);
void* LeafForward4f7910::Forward() { return leaf_target(this); }
