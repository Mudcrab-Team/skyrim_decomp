// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfc0920, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfc0920 LeafForwardfc0920::Forward
#include "LeafForwardfc0920.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfc0920::Forward() { return leaf_target(this); }
