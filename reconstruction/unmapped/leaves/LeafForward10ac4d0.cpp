// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10ac4d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10ac4d0 LeafForward10ac4d0::Forward
#include "LeafForward10ac4d0.h"
extern "C" void* leaf_target(void*);
void* LeafForward10ac4d0::Forward() { return leaf_target(this); }
