// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardff12d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xff12d0 LeafForwardff12d0::Forward
#include "LeafForwardff12d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardff12d0::Forward() { return leaf_target(this); }
