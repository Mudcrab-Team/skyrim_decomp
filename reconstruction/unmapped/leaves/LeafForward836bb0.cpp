// Source exposure: binary-analysis; no external implementation reused.
// LeafForward836bb0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x836bb0 LeafForward836bb0::Forward
#include "LeafForward836bb0.h"
extern "C" void* leaf_target(void*);
void* LeafForward836bb0::Forward() { return leaf_target(this); }
