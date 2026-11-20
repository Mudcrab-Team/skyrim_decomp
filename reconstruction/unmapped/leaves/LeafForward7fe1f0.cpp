// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7fe1f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7fe1f0 LeafForward7fe1f0::Forward
#include "LeafForward7fe1f0.h"
extern "C" void* leaf_target(void*);
void* LeafForward7fe1f0::Forward() { return leaf_target(this); }
