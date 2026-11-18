// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7df750, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7df750 LeafForward7df750::Forward
#include "LeafForward7df750.h"
extern "C" void* leaf_target(void*);
void* LeafForward7df750::Forward() { return leaf_target(this); }
