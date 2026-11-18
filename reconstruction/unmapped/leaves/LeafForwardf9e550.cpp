// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf9e550, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf9e550 LeafForwardf9e550::Forward
#include "LeafForwardf9e550.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf9e550::Forward() { return leaf_target(this); }
