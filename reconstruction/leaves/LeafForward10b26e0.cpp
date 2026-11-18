// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10b26e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10b26e0 LeafForward10b26e0::Forward
#include "LeafForward10b26e0.h"
extern "C" void* leaf_target(void*);
void* LeafForward10b26e0::Forward() { return leaf_target(this); }
