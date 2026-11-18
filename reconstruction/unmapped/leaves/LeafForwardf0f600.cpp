// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf0f600, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf0f600 LeafForwardf0f600::Forward
#include "LeafForwardf0f600.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf0f600::Forward() { return leaf_target(this); }
