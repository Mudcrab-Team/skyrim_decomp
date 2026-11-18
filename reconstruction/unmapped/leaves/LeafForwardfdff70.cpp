// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfdff70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfdff70 LeafForwardfdff70::Forward
#include "LeafForwardfdff70.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfdff70::Forward() { return leaf_target(this); }
