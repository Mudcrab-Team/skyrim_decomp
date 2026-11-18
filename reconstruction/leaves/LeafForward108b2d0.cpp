// Source exposure: binary-analysis; no external implementation reused.
// LeafForward108b2d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x108b2d0 LeafForward108b2d0::Forward
#include "LeafForward108b2d0.h"
extern "C" void* leaf_target(void*);
void* LeafForward108b2d0::Forward() { return leaf_target(this); }
