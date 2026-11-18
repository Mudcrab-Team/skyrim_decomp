// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfd2e10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfd2e10 LeafForwardfd2e10::Forward
#include "LeafForwardfd2e10.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfd2e10::Forward() { return leaf_target(this); }
