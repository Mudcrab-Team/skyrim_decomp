// Source exposure: binary-analysis; no external implementation reused.
// LeafForward80f1e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x80f1e0 LeafForward80f1e0::Forward
#include "LeafForward80f1e0.h"
extern "C" void* leaf_target(void*);
void* LeafForward80f1e0::Forward() { return leaf_target(this); }
