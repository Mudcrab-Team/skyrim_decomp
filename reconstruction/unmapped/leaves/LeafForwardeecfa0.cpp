// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardeecfa0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xeecfa0 LeafForwardeecfa0::Forward
#include "LeafForwardeecfa0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardeecfa0::Forward() { return leaf_target(this); }
