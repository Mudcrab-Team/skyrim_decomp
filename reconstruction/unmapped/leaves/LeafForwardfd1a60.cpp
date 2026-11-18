// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfd1a60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfd1a60 LeafForwardfd1a60::Forward
#include "LeafForwardfd1a60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfd1a60::Forward() { return leaf_target(this); }
