// Source exposure: binary-analysis; no external implementation reused.
// LeafForward9eca30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x9eca30 LeafForward9eca30::Forward
#include "LeafForward9eca30.h"
extern "C" void* leaf_target(void*);
void* LeafForward9eca30::Forward() { return leaf_target(this); }
