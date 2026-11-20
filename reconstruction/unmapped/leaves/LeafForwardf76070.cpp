// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf76070, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf76070 LeafForwardf76070::Forward
#include "LeafForwardf76070.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf76070::Forward() { return leaf_target(this); }
