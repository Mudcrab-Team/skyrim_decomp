// Source exposure: binary-analysis; no external implementation reused.
// LeafForward555d70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x555d70 LeafForward555d70::Forward
#include "LeafForward555d70.h"
extern "C" void* leaf_target(void*);
void* LeafForward555d70::Forward() { return leaf_target(this); }
