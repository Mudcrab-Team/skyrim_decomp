// Source exposure: binary-analysis; no external implementation reused.
// LeafForward109ed60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x109ed60 LeafForward109ed60::Forward
#include "LeafForward109ed60.h"
extern "C" void* leaf_target(void*);
void* LeafForward109ed60::Forward() { return leaf_target(this); }
