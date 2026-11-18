// Source exposure: binary-analysis; no external implementation reused.
// LeafForward80c970, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x80c970 LeafForward80c970::Forward
#include "LeafForward80c970.h"
extern "C" void* leaf_target(void*);
void* LeafForward80c970::Forward() { return leaf_target(this); }
