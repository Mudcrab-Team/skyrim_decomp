// Source exposure: binary-analysis; no external implementation reused.
// LeafForward83f8f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x83f8f0 LeafForward83f8f0::Forward
#include "LeafForward83f8f0.h"
extern "C" void* leaf_target(void*);
void* LeafForward83f8f0::Forward() { return leaf_target(this); }
