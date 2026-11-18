// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardec7f60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xec7f60 LeafForwardec7f60::Forward
#include "LeafForwardec7f60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardec7f60::Forward() { return leaf_target(this); }
