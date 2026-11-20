// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfe0d10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfe0d10 LeafForwardfe0d10::Forward
#include "LeafForwardfe0d10.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfe0d10::Forward() { return leaf_target(this); }
