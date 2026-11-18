// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf761b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf761b0 LeafForwardf761b0::Forward
#include "LeafForwardf761b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf761b0::Forward() { return leaf_target(this); }
