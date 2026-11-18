// Source exposure: binary-analysis; no external implementation reused.
// LeafForward5dfd70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x5dfd70 LeafForward5dfd70::Forward
#include "LeafForward5dfd70.h"
extern "C" void* leaf_target(void*);
void* LeafForward5dfd70::Forward() { return leaf_target(this); }
