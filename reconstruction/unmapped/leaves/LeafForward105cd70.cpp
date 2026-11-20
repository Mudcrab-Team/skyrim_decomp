// Source exposure: binary-analysis; no external implementation reused.
// LeafForward105cd70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x105cd70 LeafForward105cd70::Forward
#include "LeafForward105cd70.h"
extern "C" void* leaf_target(void*);
void* LeafForward105cd70::Forward() { return leaf_target(this); }
