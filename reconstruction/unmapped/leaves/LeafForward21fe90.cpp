// Source exposure: binary-analysis; no external implementation reused.
// LeafForward21fe90, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x21fe90 LeafForward21fe90::Forward
#include "LeafForward21fe90.h"
extern "C" void* leaf_target(void*);
void* LeafForward21fe90::Forward() { return leaf_target(this); }
