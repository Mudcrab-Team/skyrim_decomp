// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8af180, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8af180 LeafForward8af180::Forward
#include "LeafForward8af180.h"
extern "C" void* leaf_target(void*);
void* LeafForward8af180::Forward() { return leaf_target(this); }
