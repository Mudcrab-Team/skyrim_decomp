// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf761e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf761e0 LeafForwardf761e0::Forward
#include "LeafForwardf761e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf761e0::Forward() { return leaf_target(this); }
