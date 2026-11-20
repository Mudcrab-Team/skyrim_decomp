// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7b190, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7b190 LeafForwardf7b190::Forward
#include "LeafForwardf7b190.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7b190::Forward() { return leaf_target(this); }
