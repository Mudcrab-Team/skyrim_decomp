// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfc1760, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfc1760 LeafForwardfc1760::Forward
#include "LeafForwardfc1760.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfc1760::Forward() { return leaf_target(this); }
