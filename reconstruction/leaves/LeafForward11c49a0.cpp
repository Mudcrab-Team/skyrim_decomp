// Source exposure: binary-analysis; no external implementation reused.
// LeafForward11c49a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x11c49a0 LeafForward11c49a0::Forward
#include "LeafForward11c49a0.h"
extern "C" void* leaf_target(void*);
void* LeafForward11c49a0::Forward() { return leaf_target(this); }
