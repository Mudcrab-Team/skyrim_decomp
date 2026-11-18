// Source exposure: binary-analysis; no external implementation reused.
// LeafForward14c670, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x14c670 LeafForward14c670::Forward
#include "LeafForward14c670.h"
extern "C" void* leaf_target(void*);
void* LeafForward14c670::Forward() { return leaf_target(this); }
