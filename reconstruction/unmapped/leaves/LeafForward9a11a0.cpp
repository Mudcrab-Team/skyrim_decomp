// Source exposure: binary-analysis; no external implementation reused.
// LeafForward9a11a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x9a11a0 LeafForward9a11a0::Forward
#include "LeafForward9a11a0.h"
extern "C" void* leaf_target(void*);
void* LeafForward9a11a0::Forward() { return leaf_target(this); }
