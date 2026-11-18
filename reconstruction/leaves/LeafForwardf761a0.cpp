// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf761a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf761a0 LeafForwardf761a0::Forward
#include "LeafForwardf761a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf761a0::Forward() { return leaf_target(this); }
