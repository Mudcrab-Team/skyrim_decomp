// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfd1a40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfd1a40 LeafForwardfd1a40::Forward
#include "LeafForwardfd1a40.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfd1a40::Forward() { return leaf_target(this); }
