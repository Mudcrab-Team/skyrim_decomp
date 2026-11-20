// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfd8c40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfd8c40 LeafForwardfd8c40::Forward
#include "LeafForwardfd8c40.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfd8c40::Forward() { return leaf_target(this); }
