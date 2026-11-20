// Source exposure: binary-analysis; no external implementation reused.
// LeafForward556ba0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x556ba0 LeafForward556ba0::Forward
#include "LeafForward556ba0.h"
extern "C" void* leaf_target(void*);
void* LeafForward556ba0::Forward() { return leaf_target(this); }
