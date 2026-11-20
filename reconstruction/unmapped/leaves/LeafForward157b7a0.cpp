// Source exposure: binary-analysis; no external implementation reused.
// LeafForward157b7a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x157b7a0 LeafForward157b7a0::Forward
#include "LeafForward157b7a0.h"
extern "C" void* leaf_target(void*);
void* LeafForward157b7a0::Forward() { return leaf_target(this); }
