// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10ecde0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10ecde0 LeafForward10ecde0::Forward
#include "LeafForward10ecde0.h"
extern "C" void* leaf_target(void*);
void* LeafForward10ecde0::Forward() { return leaf_target(this); }
