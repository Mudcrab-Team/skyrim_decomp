// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardef2690, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xef2690 LeafForwardef2690::Forward
#include "LeafForwardef2690.h"
extern "C" void* leaf_target(void*);
void* LeafForwardef2690::Forward() { return leaf_target(this); }
