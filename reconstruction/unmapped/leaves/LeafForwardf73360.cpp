// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf73360, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf73360 LeafForwardf73360::Forward
#include "LeafForwardf73360.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf73360::Forward() { return leaf_target(this); }
