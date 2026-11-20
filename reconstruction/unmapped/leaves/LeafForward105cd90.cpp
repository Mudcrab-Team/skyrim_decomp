// Source exposure: binary-analysis; no external implementation reused.
// LeafForward105cd90, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x105cd90 LeafForward105cd90::Forward
#include "LeafForward105cd90.h"
extern "C" void* leaf_target(void*);
void* LeafForward105cd90::Forward() { return leaf_target(this); }
