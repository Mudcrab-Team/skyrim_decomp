// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1e660, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1e660 LeafForwardf1e660::Forward
#include "LeafForwardf1e660.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1e660::Forward() { return leaf_target(this); }
