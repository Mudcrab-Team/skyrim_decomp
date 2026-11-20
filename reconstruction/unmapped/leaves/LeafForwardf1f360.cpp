// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1f360, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1f360 LeafForwardf1f360::Forward
#include "LeafForwardf1f360.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1f360::Forward() { return leaf_target(this); }
