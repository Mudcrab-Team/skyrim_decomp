// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardef1e40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xef1e40 LeafForwardef1e40::Forward
#include "LeafForwardef1e40.h"
extern "C" void* leaf_target(void*);
void* LeafForwardef1e40::Forward() { return leaf_target(this); }
