// Source exposure: binary-analysis; no external implementation reused.
// LeafForward837340, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x837340 LeafForward837340::Forward
#include "LeafForward837340.h"
extern "C" void* leaf_target(void*);
void* LeafForward837340::Forward() { return leaf_target(this); }
