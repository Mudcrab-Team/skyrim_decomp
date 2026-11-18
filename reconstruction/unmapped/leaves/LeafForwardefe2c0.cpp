// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardefe2c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xefe2c0 LeafForwardefe2c0::Forward
#include "LeafForwardefe2c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardefe2c0::Forward() { return leaf_target(this); }
