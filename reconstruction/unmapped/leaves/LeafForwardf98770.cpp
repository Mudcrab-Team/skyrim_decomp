// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf98770, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf98770 LeafForwardf98770::Forward
#include "LeafForwardf98770.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf98770::Forward() { return leaf_target(this); }
