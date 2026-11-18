// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1e640, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1e640 LeafForwardf1e640::Forward
#include "LeafForwardf1e640.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1e640::Forward() { return leaf_target(this); }
