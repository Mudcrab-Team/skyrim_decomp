// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1571100, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1571100 LeafForward1571100::Forward
#include "LeafForward1571100.h"
extern "C" void* leaf_target(void*);
void* LeafForward1571100::Forward() { return leaf_target(this); }
