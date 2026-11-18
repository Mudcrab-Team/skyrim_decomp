// Source exposure: binary-analysis; no external implementation reused.
// LeafForward836730, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x836730 LeafForward836730::Forward
#include "LeafForward836730.h"
extern "C" void* leaf_target(void*);
void* LeafForward836730::Forward() { return leaf_target(this); }
