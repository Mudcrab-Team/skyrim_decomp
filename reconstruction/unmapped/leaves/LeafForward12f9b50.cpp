// Source exposure: binary-analysis; no external implementation reused.
// LeafForward12f9b50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x12f9b50 LeafForward12f9b50::Forward
#include "LeafForward12f9b50.h"
extern "C" void* leaf_target(void*);
void* LeafForward12f9b50::Forward() { return leaf_target(this); }
