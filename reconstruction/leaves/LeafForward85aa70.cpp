// Source exposure: binary-analysis; no external implementation reused.
// LeafForward85aa70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x85aa70 LeafForward85aa70::Forward
#include "LeafForward85aa70.h"
extern "C" void* leaf_target(void*);
void* LeafForward85aa70::Forward() { return leaf_target(this); }
