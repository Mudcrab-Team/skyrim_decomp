// Source exposure: binary-analysis; no external implementation reused.
// LeafForward105cd50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x105cd50 LeafForward105cd50::Forward
#include "LeafForward105cd50.h"
extern "C" void* leaf_target(void*);
void* LeafForward105cd50::Forward() { return leaf_target(this); }
