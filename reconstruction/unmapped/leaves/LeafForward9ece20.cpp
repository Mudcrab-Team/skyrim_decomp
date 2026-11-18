// Source exposure: binary-analysis; no external implementation reused.
// LeafForward9ece20, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x9ece20 LeafForward9ece20::Forward
#include "LeafForward9ece20.h"
extern "C" void* leaf_target(void*);
void* LeafForward9ece20::Forward() { return leaf_target(this); }
