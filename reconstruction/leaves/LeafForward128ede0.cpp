// Source exposure: binary-analysis; no external implementation reused.
// LeafForward128ede0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x128ede0 LeafForward128ede0::Forward
#include "LeafForward128ede0.h"
extern "C" void* leaf_target(void*);
void* LeafForward128ede0::Forward() { return leaf_target(this); }
