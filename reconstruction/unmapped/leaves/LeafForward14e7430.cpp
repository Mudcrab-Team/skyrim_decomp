// Source exposure: binary-analysis; no external implementation reused.
// LeafForward14e7430, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x14e7430 LeafForward14e7430::Forward
#include "LeafForward14e7430.h"
extern "C" void* leaf_target(void*);
void* LeafForward14e7430::Forward() { return leaf_target(this); }
