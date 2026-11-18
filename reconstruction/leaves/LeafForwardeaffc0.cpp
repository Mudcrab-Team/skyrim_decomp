// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardeaffc0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xeaffc0 LeafForwardeaffc0::Forward
#include "LeafForwardeaffc0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardeaffc0::Forward() { return leaf_target(this); }
