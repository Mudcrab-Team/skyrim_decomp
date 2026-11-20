// Source exposure: binary-analysis; no external implementation reused.
// LeafForward990c10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x990c10 LeafForward990c10::Forward
#include "LeafForward990c10.h"
extern "C" void* leaf_target(void*);
void* LeafForward990c10::Forward() { return leaf_target(this); }
