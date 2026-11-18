// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbe36d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbe36d0 LeafForwardbe36d0::Forward
#include "LeafForwardbe36d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbe36d0::Forward() { return leaf_target(this); }
