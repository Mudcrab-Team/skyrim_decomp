// Source exposure: binary-analysis; no external implementation reused.
// LeafForwarded54e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xed54e0 LeafForwarded54e0::Forward
#include "LeafForwarded54e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwarded54e0::Forward() { return leaf_target(this); }
