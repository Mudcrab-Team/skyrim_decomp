// Source exposure: binary-analysis; no external implementation reused.
// LeafForward4e3390, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x4e3390 LeafForward4e3390::Forward
#include "LeafForward4e3390.h"
extern "C" void* leaf_target(void*);
void* LeafForward4e3390::Forward() { return leaf_target(this); }
