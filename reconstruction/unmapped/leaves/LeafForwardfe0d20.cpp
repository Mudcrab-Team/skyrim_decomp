// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfe0d20, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfe0d20 LeafForwardfe0d20::Forward
#include "LeafForwardfe0d20.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfe0d20::Forward() { return leaf_target(this); }
