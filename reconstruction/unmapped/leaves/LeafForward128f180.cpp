// Source exposure: binary-analysis; no external implementation reused.
// LeafForward128f180, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x128f180 LeafForward128f180::Forward
#include "LeafForward128f180.h"
extern "C" void* leaf_target(void*);
void* LeafForward128f180::Forward() { return leaf_target(this); }
