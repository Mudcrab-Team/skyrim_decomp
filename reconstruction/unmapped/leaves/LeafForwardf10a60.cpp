// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf10a60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf10a60 LeafForwardf10a60::Forward
#include "LeafForwardf10a60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf10a60::Forward() { return leaf_target(this); }
