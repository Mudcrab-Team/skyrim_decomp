// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf68690, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf68690 LeafForwardf68690::Forward
#include "LeafForwardf68690.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf68690::Forward() { return leaf_target(this); }
