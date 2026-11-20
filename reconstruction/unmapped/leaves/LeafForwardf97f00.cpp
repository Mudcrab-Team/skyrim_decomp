// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf97f00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf97f00 LeafForwardf97f00::Forward
#include "LeafForwardf97f00.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf97f00::Forward() { return leaf_target(this); }
