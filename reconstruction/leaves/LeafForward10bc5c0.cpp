// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10bc5c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10bc5c0 LeafForward10bc5c0::Forward
#include "LeafForward10bc5c0.h"
extern "C" void* leaf_target(void*);
void* LeafForward10bc5c0::Forward() { return leaf_target(this); }
