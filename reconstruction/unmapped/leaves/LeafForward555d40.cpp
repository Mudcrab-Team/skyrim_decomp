// Source exposure: binary-analysis; no external implementation reused.
// LeafForward555d40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x555d40 LeafForward555d40::Forward
#include "LeafForward555d40.h"
extern "C" void* leaf_target(void*);
void* LeafForward555d40::Forward() { return leaf_target(this); }
