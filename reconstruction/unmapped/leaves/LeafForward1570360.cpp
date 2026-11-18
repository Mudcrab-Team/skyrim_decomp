// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1570360, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1570360 LeafForward1570360::Forward
#include "LeafForward1570360.h"
extern "C" void* leaf_target(void*);
void* LeafForward1570360::Forward() { return leaf_target(this); }
