// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfe0d30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfe0d30 LeafForwardfe0d30::Forward
#include "LeafForwardfe0d30.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfe0d30::Forward() { return leaf_target(this); }
