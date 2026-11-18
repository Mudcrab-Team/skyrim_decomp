// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf74510, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf74510 LeafForwardf74510::Forward
#include "LeafForwardf74510.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf74510::Forward() { return leaf_target(this); }
