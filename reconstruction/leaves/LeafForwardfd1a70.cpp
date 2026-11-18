// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfd1a70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfd1a70 LeafForwardfd1a70::Forward
#include "LeafForwardfd1a70.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfd1a70::Forward() { return leaf_target(this); }
