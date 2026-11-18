// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbee3b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbee3b0 LeafForwardbee3b0::Forward
#include "LeafForwardbee3b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbee3b0::Forward() { return leaf_target(this); }
