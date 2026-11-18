// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf09290, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf09290 LeafForwardf09290::Forward
#include "LeafForwardf09290.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf09290::Forward() { return leaf_target(this); }
