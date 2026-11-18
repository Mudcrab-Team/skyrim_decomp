// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf6cbb0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf6cbb0 LeafForwardf6cbb0::Forward
#include "LeafForwardf6cbb0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf6cbb0::Forward() { return leaf_target(this); }
