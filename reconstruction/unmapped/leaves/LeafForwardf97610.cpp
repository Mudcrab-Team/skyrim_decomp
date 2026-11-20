// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf97610, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf97610 LeafForwardf97610::Forward
#include "LeafForwardf97610.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf97610::Forward() { return leaf_target(this); }
