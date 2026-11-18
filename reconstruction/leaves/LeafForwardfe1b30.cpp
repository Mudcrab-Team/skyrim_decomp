// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfe1b30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfe1b30 LeafForwardfe1b30::Forward
#include "LeafForwardfe1b30.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfe1b30::Forward() { return leaf_target(this); }
