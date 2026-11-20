// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardb034d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xb034d0 LeafForwardb034d0::Forward
#include "LeafForwardb034d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardb034d0::Forward() { return leaf_target(this); }
