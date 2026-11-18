// Source exposure: binary-analysis; no external implementation reused.
// LeafForward9bfde0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x9bfde0 LeafForward9bfde0::Forward
#include "LeafForward9bfde0.h"
extern "C" void* leaf_target(void*);
void* LeafForward9bfde0::Forward() { return leaf_target(this); }
