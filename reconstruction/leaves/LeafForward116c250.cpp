// Source exposure: binary-analysis; no external implementation reused.
// LeafForward116c250, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x116c250 LeafForward116c250::Forward
#include "LeafForward116c250.h"
extern "C" void* leaf_target(void*);
void* LeafForward116c250::Forward() { return leaf_target(this); }
