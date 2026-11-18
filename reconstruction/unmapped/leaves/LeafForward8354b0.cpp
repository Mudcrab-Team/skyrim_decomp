// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8354b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8354b0 LeafForward8354b0::Forward
#include "LeafForward8354b0.h"
extern "C" void* leaf_target(void*);
void* LeafForward8354b0::Forward() { return leaf_target(this); }
