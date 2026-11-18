// Source exposure: binary-analysis; no external implementation reused.
// LeafForward13db6c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x13db6c0 LeafForward13db6c0::Forward
#include "LeafForward13db6c0.h"
extern "C" void* leaf_target(void*);
void* LeafForward13db6c0::Forward() { return leaf_target(this); }
