// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbc37b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbc37b0 LeafForwardbc37b0::Forward
#include "LeafForwardbc37b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbc37b0::Forward() { return leaf_target(this); }
