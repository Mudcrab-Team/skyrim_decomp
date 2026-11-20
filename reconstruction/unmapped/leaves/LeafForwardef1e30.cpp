// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardef1e30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xef1e30 LeafForwardef1e30::Forward
#include "LeafForwardef1e30.h"
extern "C" void* leaf_target(void*);
void* LeafForwardef1e30::Forward() { return leaf_target(this); }
