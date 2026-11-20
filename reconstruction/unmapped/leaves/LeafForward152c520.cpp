// Source exposure: binary-analysis; no external implementation reused.
// LeafForward152c520, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x152c520 LeafForward152c520::Forward
#include "LeafForward152c520.h"
extern "C" void* leaf_target(void*);
void* LeafForward152c520::Forward() { return leaf_target(this); }
