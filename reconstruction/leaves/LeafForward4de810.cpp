// Source exposure: binary-analysis; no external implementation reused.
// LeafForward4de810, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x4de810 LeafForward4de810::Forward
#include "LeafForward4de810.h"
extern "C" void* leaf_target(void*);
void* LeafForward4de810::Forward() { return leaf_target(this); }
