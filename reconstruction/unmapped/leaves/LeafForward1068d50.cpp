// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1068d50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1068d50 LeafForward1068d50::Forward
#include "LeafForward1068d50.h"
extern "C" void* leaf_target(void*);
void* LeafForward1068d50::Forward() { return leaf_target(this); }
