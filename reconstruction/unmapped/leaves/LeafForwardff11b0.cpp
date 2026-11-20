// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardff11b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xff11b0 LeafForwardff11b0::Forward
#include "LeafForwardff11b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardff11b0::Forward() { return leaf_target(this); }
