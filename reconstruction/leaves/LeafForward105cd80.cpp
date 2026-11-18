// Source exposure: binary-analysis; no external implementation reused.
// LeafForward105cd80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x105cd80 LeafForward105cd80::Forward
#include "LeafForward105cd80.h"
extern "C" void* leaf_target(void*);
void* LeafForward105cd80::Forward() { return leaf_target(this); }
