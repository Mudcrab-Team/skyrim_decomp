// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf69640, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf69640 LeafForwardf69640::Forward
#include "LeafForwardf69640.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf69640::Forward() { return leaf_target(this); }
