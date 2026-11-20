// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1085250, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1085250 LeafForward1085250::Forward
#include "LeafForward1085250.h"
extern "C" void* leaf_target(void*);
void* LeafForward1085250::Forward() { return leaf_target(this); }
