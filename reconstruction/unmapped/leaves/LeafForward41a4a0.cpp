// Source exposure: binary-analysis; no external implementation reused.
// LeafForward41a4a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x41a4a0 LeafForward41a4a0::Forward
#include "LeafForward41a4a0.h"
extern "C" void* leaf_target(void*);
void* LeafForward41a4a0::Forward() { return leaf_target(this); }
