// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf9e510, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf9e510 LeafForwardf9e510::Forward
#include "LeafForwardf9e510.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf9e510::Forward() { return leaf_target(this); }
