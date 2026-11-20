// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1571110, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1571110 LeafForward1571110::Forward
#include "LeafForward1571110.h"
extern "C" void* leaf_target(void*);
void* LeafForward1571110::Forward() { return leaf_target(this); }
