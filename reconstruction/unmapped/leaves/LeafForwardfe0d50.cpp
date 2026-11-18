// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfe0d50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfe0d50 LeafForwardfe0d50::Forward
#include "LeafForwardfe0d50.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfe0d50::Forward() { return leaf_target(this); }
