// Source exposure: binary-analysis; no external implementation reused.
// LeafForward82e7e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x82e7e0 LeafForward82e7e0::Forward
#include "LeafForward82e7e0.h"
extern "C" void* leaf_target(void*);
void* LeafForward82e7e0::Forward() { return leaf_target(this); }
