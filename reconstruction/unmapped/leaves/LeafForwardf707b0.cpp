// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf707b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf707b0 LeafForwardf707b0::Forward
#include "LeafForwardf707b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf707b0::Forward() { return leaf_target(this); }
