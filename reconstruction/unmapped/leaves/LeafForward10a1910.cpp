// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10a1910, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10a1910 LeafForward10a1910::Forward
#include "LeafForward10a1910.h"
extern "C" void* leaf_target(void*);
void* LeafForward10a1910::Forward() { return leaf_target(this); }
