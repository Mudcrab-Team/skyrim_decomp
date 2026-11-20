// Source exposure: binary-analysis; no external implementation reused.
// LeafForward15c7a70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x15c7a70 LeafForward15c7a70::Forward
#include "LeafForward15c7a70.h"
extern "C" void* leaf_target(void*);
void* LeafForward15c7a70::Forward() { return leaf_target(this); }
