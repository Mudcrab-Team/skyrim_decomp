// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf64510, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf64510 LeafForwardf64510::Forward
#include "LeafForwardf64510.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf64510::Forward() { return leaf_target(this); }
