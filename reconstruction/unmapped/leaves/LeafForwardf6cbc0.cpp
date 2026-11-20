// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf6cbc0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf6cbc0 LeafForwardf6cbc0::Forward
#include "LeafForwardf6cbc0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf6cbc0::Forward() { return leaf_target(this); }
