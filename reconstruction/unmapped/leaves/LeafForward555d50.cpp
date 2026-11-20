// Source exposure: binary-analysis; no external implementation reused.
// LeafForward555d50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x555d50 LeafForward555d50::Forward
#include "LeafForward555d50.h"
extern "C" void* leaf_target(void*);
void* LeafForward555d50::Forward() { return leaf_target(this); }
