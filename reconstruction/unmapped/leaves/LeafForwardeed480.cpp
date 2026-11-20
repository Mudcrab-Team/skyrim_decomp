// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardeed480, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xeed480 LeafForwardeed480::Forward
#include "LeafForwardeed480.h"
extern "C" void* leaf_target(void*);
void* LeafForwardeed480::Forward() { return leaf_target(this); }
