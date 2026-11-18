// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1496400, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1496400 LeafForward1496400::Forward
#include "LeafForward1496400.h"
extern "C" void* leaf_target(void*);
void* LeafForward1496400::Forward() { return leaf_target(this); }
