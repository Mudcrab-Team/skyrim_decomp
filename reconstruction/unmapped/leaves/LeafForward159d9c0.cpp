// Source exposure: binary-analysis; no external implementation reused.
// LeafForward159d9c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x159d9c0 LeafForward159d9c0::Forward
#include "LeafForward159d9c0.h"
extern "C" void* leaf_target(void*);
void* LeafForward159d9c0::Forward() { return leaf_target(this); }
