// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8ea670, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8ea670 LeafForward8ea670::Forward
#include "LeafForward8ea670.h"
extern "C" void* leaf_target(void*);
void* LeafForward8ea670::Forward() { return leaf_target(this); }
