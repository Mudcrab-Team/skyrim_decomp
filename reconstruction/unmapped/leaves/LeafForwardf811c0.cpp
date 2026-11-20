// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf811c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf811c0 LeafForwardf811c0::Forward
#include "LeafForwardf811c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf811c0::Forward() { return leaf_target(this); }
