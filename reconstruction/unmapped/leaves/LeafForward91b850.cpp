// Source exposure: binary-analysis; no external implementation reused.
// LeafForward91b850, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x91b850 LeafForward91b850::Forward
#include "LeafForward91b850.h"
extern "C" void* leaf_target(void*);
void* LeafForward91b850::Forward() { return leaf_target(this); }
