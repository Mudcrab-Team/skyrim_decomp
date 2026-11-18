// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardba8b70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xba8b70 LeafForwardba8b70::Forward
#include "LeafForwardba8b70.h"
extern "C" void* leaf_target(void*);
void* LeafForwardba8b70::Forward() { return leaf_target(this); }
