// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfd2e00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfd2e00 LeafForwardfd2e00::Forward
#include "LeafForwardfd2e00.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfd2e00::Forward() { return leaf_target(this); }
