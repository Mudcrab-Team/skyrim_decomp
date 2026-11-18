// Source exposure: binary-analysis; no external implementation reused.
// LeafForward153af80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x153af80 LeafForward153af80::Forward
#include "LeafForward153af80.h"
extern "C" void* leaf_target(void*);
void* LeafForward153af80::Forward() { return leaf_target(this); }
