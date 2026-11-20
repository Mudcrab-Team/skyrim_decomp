// Source exposure: binary-analysis; no external implementation reused.
// LeafForward80aff0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x80aff0 LeafForward80aff0::Forward
#include "LeafForward80aff0.h"
extern "C" void* leaf_target(void*);
void* LeafForward80aff0::Forward() { return leaf_target(this); }
