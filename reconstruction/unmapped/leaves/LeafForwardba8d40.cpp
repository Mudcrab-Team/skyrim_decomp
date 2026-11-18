// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardba8d40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xba8d40 LeafForwardba8d40::Forward
#include "LeafForwardba8d40.h"
extern "C" void* leaf_target(void*);
void* LeafForwardba8d40::Forward() { return leaf_target(this); }
