// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardc59160, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xc59160 LeafForwardc59160::Forward
#include "LeafForwardc59160.h"
extern "C" void* leaf_target(void*);
void* LeafForwardc59160::Forward() { return leaf_target(this); }
