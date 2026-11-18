// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10a71f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10a71f0 LeafForward10a71f0::Forward
#include "LeafForward10a71f0.h"
extern "C" void* leaf_target(void*);
void* LeafForward10a71f0::Forward() { return leaf_target(this); }
