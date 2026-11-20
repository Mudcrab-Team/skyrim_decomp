// Source exposure: binary-analysis; no external implementation reused.
// LeafForward91bde0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x91bde0 LeafForward91bde0::Forward
#include "LeafForward91bde0.h"
extern "C" void* leaf_target(void*);
void* LeafForward91bde0::Forward() { return leaf_target(this); }
