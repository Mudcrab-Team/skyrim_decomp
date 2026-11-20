// Source exposure: binary-analysis; no external implementation reused.
// LeafForward108cb30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x108cb30 LeafForward108cb30::Forward
#include "LeafForward108cb30.h"
extern "C" void* leaf_target(void*);
void* LeafForward108cb30::Forward() { return leaf_target(this); }
