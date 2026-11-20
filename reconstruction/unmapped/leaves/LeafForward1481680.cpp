// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1481680, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1481680 LeafForward1481680::Forward
#include "LeafForward1481680.h"
extern "C" void* leaf_target(void*);
void* LeafForward1481680::Forward() { return leaf_target(this); }
