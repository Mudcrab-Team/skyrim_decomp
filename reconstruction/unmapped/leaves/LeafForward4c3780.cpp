// Source exposure: binary-analysis; no external implementation reused.
// LeafForward4c3780, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x4c3780 LeafForward4c3780::Forward
#include "LeafForward4c3780.h"
extern "C" void* leaf_target(void*);
void* LeafForward4c3780::Forward() { return leaf_target(this); }
