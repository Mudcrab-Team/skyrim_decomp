// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf811e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf811e0 LeafForwardf811e0::Forward
#include "LeafForwardf811e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf811e0::Forward() { return leaf_target(this); }
