// Source exposure: binary-analysis; no external implementation reused.
// LeafForward890df0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x890df0 LeafForward890df0::Forward
#include "LeafForward890df0.h"
extern "C" void* leaf_target(void*);
void* LeafForward890df0::Forward() { return leaf_target(this); }
