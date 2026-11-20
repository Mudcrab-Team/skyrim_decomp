// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardff11a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xff11a0 LeafForwardff11a0::Forward
#include "LeafForwardff11a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardff11a0::Forward() { return leaf_target(this); }
