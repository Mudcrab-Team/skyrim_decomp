// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf860b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf860b0 LeafForwardf860b0::Forward
#include "LeafForwardf860b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf860b0::Forward() { return leaf_target(this); }
