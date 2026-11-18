// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf9c440, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf9c440 LeafForwardf9c440::Forward
#include "LeafForwardf9c440.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf9c440::Forward() { return leaf_target(this); }
