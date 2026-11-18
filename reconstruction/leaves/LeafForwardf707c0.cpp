// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf707c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf707c0 LeafForwardf707c0::Forward
#include "LeafForwardf707c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf707c0::Forward() { return leaf_target(this); }
