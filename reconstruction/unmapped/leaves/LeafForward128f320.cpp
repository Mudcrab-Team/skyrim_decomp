// Source exposure: binary-analysis; no external implementation reused.
// LeafForward128f320, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x128f320 LeafForward128f320::Forward
#include "LeafForward128f320.h"
extern "C" void* leaf_target(void*);
void* LeafForward128f320::Forward() { return leaf_target(this); }
