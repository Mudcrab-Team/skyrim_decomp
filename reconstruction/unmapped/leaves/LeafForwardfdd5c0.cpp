// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfdd5c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfdd5c0 LeafForwardfdd5c0::Forward
#include "LeafForwardfdd5c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfdd5c0::Forward() { return leaf_target(this); }
