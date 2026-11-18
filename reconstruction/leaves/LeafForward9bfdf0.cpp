// Source exposure: binary-analysis; no external implementation reused.
// LeafForward9bfdf0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x9bfdf0 LeafForward9bfdf0::Forward
#include "LeafForward9bfdf0.h"
extern "C" void* leaf_target(void*);
void* LeafForward9bfdf0::Forward() { return leaf_target(this); }
