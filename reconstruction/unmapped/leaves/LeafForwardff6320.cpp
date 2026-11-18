// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardff6320, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xff6320 LeafForwardff6320::Forward
#include "LeafForwardff6320.h"
extern "C" void* leaf_target(void*);
void* LeafForwardff6320::Forward() { return leaf_target(this); }
