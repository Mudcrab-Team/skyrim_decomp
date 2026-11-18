// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8cd560, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8cd560 LeafForward8cd560::Forward
#include "LeafForward8cd560.h"
extern "C" void* leaf_target(void*);
void* LeafForward8cd560::Forward() { return leaf_target(this); }
