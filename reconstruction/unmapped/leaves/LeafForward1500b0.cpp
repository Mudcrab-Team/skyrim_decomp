// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1500b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1500b0 LeafForward1500b0::Forward
#include "LeafForward1500b0.h"
extern "C" void* leaf_target(void*);
void* LeafForward1500b0::Forward() { return leaf_target(this); }
