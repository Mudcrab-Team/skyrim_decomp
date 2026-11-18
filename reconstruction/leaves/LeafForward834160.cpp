// Source exposure: binary-analysis; no external implementation reused.
// LeafForward834160, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x834160 LeafForward834160::Forward
#include "LeafForward834160.h"
extern "C" void* leaf_target(void*);
void* LeafForward834160::Forward() { return leaf_target(this); }
