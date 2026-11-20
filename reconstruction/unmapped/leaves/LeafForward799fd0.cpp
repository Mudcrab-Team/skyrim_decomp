// Source exposure: binary-analysis; no external implementation reused.
// LeafForward799fd0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x799fd0 LeafForward799fd0::Forward
#include "LeafForward799fd0.h"
extern "C" void* leaf_target(void*);
void* LeafForward799fd0::Forward() { return leaf_target(this); }
