// Source exposure: binary-analysis; no external implementation reused.
// LeafForward116c9b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x116c9b0 LeafForward116c9b0::Forward
#include "LeafForward116c9b0.h"
extern "C" void* leaf_target(void*);
void* LeafForward116c9b0::Forward() { return leaf_target(this); }
