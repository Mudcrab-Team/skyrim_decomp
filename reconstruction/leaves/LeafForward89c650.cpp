// Source exposure: binary-analysis; no external implementation reused.
// LeafForward89c650, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x89c650 LeafForward89c650::Forward
#include "LeafForward89c650.h"
extern "C" void* leaf_target(void*);
void* LeafForward89c650::Forward() { return leaf_target(this); }
