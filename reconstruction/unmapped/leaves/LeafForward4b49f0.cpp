// Source exposure: binary-analysis; no external implementation reused.
// LeafForward4b49f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x4b49f0 LeafForward4b49f0::Forward
#include "LeafForward4b49f0.h"
extern "C" void* leaf_target(void*);
void* LeafForward4b49f0::Forward() { return leaf_target(this); }
