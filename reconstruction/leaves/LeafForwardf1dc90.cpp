// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1dc90, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1dc90 LeafForwardf1dc90::Forward
#include "LeafForwardf1dc90.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1dc90::Forward() { return leaf_target(this); }
