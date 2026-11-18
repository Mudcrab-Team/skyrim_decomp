// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa0050, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa0050 LeafForwardfa0050::Forward
#include "LeafForwardfa0050.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa0050::Forward() { return leaf_target(this); }
