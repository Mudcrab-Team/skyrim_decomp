// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8a4980, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8a4980 LeafForward8a4980::Forward
#include "LeafForward8a4980.h"
extern "C" void* leaf_target(void*);
void* LeafForward8a4980::Forward() { return leaf_target(this); }
