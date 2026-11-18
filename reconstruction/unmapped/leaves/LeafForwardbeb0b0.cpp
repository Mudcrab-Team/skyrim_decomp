// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbeb0b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbeb0b0 LeafForwardbeb0b0::Forward
#include "LeafForwardbeb0b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbeb0b0::Forward() { return leaf_target(this); }
