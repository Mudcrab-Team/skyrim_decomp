// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8aea50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8aea50 LeafForward8aea50::Forward
#include "LeafForward8aea50.h"
extern "C" void* leaf_target(void*);
void* LeafForward8aea50::Forward() { return leaf_target(this); }
