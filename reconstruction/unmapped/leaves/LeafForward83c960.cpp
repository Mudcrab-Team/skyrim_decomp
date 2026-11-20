// Source exposure: binary-analysis; no external implementation reused.
// LeafForward83c960, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x83c960 LeafForward83c960::Forward
#include "LeafForward83c960.h"
extern "C" void* leaf_target(void*);
void* LeafForward83c960::Forward() { return leaf_target(this); }
