// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8af370, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8af370 LeafForward8af370::Forward
#include "LeafForward8af370.h"
extern "C" void* leaf_target(void*);
void* LeafForward8af370::Forward() { return leaf_target(this); }
