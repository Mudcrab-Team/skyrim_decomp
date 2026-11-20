// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1553250, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1553250 LeafForward1553250::Forward
#include "LeafForward1553250.h"
extern "C" void* leaf_target(void*);
void* LeafForward1553250::Forward() { return leaf_target(this); }
