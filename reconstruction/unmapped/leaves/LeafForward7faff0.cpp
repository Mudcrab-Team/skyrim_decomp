// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7faff0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7faff0 LeafForward7faff0::Forward
#include "LeafForward7faff0.h"
extern "C" void* leaf_target(void*);
void* LeafForward7faff0::Forward() { return leaf_target(this); }
