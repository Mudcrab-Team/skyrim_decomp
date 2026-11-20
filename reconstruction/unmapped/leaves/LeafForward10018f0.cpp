// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10018f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10018f0 LeafForward10018f0::Forward
#include "LeafForward10018f0.h"
extern "C" void* leaf_target(void*);
void* LeafForward10018f0::Forward() { return leaf_target(this); }
