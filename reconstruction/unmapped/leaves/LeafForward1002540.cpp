// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1002540, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1002540 LeafForward1002540::Forward
#include "LeafForward1002540.h"
extern "C" void* leaf_target(void*);
void* LeafForward1002540::Forward() { return leaf_target(this); }
