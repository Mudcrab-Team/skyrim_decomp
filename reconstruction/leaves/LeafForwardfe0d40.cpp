// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfe0d40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfe0d40 LeafForwardfe0d40::Forward
#include "LeafForwardfe0d40.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfe0d40::Forward() { return leaf_target(this); }
