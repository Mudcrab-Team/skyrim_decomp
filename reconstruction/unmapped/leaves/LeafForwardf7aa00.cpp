// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7aa00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7aa00 LeafForwardf7aa00::Forward
#include "LeafForwardf7aa00.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7aa00::Forward() { return leaf_target(this); }
