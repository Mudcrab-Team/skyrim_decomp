// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10030b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10030b0 LeafForward10030b0::Forward
#include "LeafForward10030b0.h"
extern "C" void* leaf_target(void*);
void* LeafForward10030b0::Forward() { return leaf_target(this); }
