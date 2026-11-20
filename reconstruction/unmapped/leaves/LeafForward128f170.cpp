// Source exposure: binary-analysis; no external implementation reused.
// LeafForward128f170, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x128f170 LeafForward128f170::Forward
#include "LeafForward128f170.h"
extern "C" void* leaf_target(void*);
void* LeafForward128f170::Forward() { return leaf_target(this); }
