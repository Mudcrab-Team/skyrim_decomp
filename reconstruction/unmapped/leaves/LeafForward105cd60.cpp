// Source exposure: binary-analysis; no external implementation reused.
// LeafForward105cd60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x105cd60 LeafForward105cd60::Forward
#include "LeafForward105cd60.h"
extern "C" void* leaf_target(void*);
void* LeafForward105cd60::Forward() { return leaf_target(this); }
