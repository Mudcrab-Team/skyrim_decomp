// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf78510, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf78510 LeafForwardf78510::Forward
#include "LeafForwardf78510.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf78510::Forward() { return leaf_target(this); }
