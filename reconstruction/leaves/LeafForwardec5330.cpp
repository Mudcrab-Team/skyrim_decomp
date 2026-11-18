// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardec5330, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xec5330 LeafForwardec5330::Forward
#include "LeafForwardec5330.h"
extern "C" void* leaf_target(void*);
void* LeafForwardec5330::Forward() { return leaf_target(this); }
