// Source exposure: binary-analysis; no external implementation reused.
// LeafForward109ed30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x109ed30 LeafForward109ed30::Forward
#include "LeafForward109ed30.h"
extern "C" void* leaf_target(void*);
void* LeafForward109ed30::Forward() { return leaf_target(this); }
