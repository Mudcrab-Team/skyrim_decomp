// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfd3340, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfd3340 LeafForwardfd3340::Forward
#include "LeafForwardfd3340.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfd3340::Forward() { return leaf_target(this); }
