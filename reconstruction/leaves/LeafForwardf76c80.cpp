// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf76c80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf76c80 LeafForwardf76c80::Forward
#include "LeafForwardf76c80.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf76c80::Forward() { return leaf_target(this); }
