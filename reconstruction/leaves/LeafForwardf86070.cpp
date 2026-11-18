// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf86070, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf86070 LeafForwardf86070::Forward
#include "LeafForwardf86070.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf86070::Forward() { return leaf_target(this); }
