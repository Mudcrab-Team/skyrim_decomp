// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardce8590, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xce8590 LeafForwardce8590::Forward
#include "LeafForwardce8590.h"
extern "C" void* leaf_target(void*);
void* LeafForwardce8590::Forward() { return leaf_target(this); }
