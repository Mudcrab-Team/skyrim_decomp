// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1082d60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1082d60 LeafForward1082d60::Forward
#include "LeafForward1082d60.h"
extern "C" void* leaf_target(void*);
void* LeafForward1082d60::Forward() { return leaf_target(this); }
