// Source exposure: binary-analysis; no external implementation reused.
// LeafForward556bb0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x556bb0 LeafForward556bb0::Forward
#include "LeafForward556bb0.h"
extern "C" void* leaf_target(void*);
void* LeafForward556bb0::Forward() { return leaf_target(this); }
