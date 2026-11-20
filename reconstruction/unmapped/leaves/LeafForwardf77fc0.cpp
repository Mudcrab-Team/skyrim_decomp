// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf77fc0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf77fc0 LeafForwardf77fc0::Forward
#include "LeafForwardf77fc0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf77fc0::Forward() { return leaf_target(this); }
