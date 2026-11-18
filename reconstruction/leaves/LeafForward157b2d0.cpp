// Source exposure: binary-analysis; no external implementation reused.
// LeafForward157b2d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x157b2d0 LeafForward157b2d0::Forward
#include "LeafForward157b2d0.h"
extern "C" void* leaf_target(void*);
void* LeafForward157b2d0::Forward() { return leaf_target(this); }
