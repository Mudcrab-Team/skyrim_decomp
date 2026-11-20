// Source exposure: binary-analysis; no external implementation reused.
// LeafForward555d60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x555d60 LeafForward555d60::Forward
#include "LeafForward555d60.h"
extern "C" void* leaf_target(void*);
void* LeafForward555d60::Forward() { return leaf_target(this); }
