// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardaeca70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xaeca70 LeafForwardaeca70::Forward
#include "LeafForwardaeca70.h"
extern "C" void* leaf_target(void*);
void* LeafForwardaeca70::Forward() { return leaf_target(this); }
