// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfc0a40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfc0a40 LeafForwardfc0a40::Forward
#include "LeafForwardfc0a40.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfc0a40::Forward() { return leaf_target(this); }
