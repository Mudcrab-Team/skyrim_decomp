// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1087710, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1087710 LeafForward1087710::Forward
#include "LeafForward1087710.h"
extern "C" void* leaf_target(void*);
void* LeafForward1087710::Forward() { return leaf_target(this); }
