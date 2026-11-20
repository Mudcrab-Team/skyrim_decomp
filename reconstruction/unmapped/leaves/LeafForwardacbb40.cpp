// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardacbb40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xacbb40 LeafForwardacbb40::Forward
#include "LeafForwardacbb40.h"
extern "C" void* leaf_target(void*);
void* LeafForwardacbb40::Forward() { return leaf_target(this); }
