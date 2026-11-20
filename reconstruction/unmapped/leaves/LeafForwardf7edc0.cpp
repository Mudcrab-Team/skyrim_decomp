// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7edc0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7edc0 LeafForwardf7edc0::Forward
#include "LeafForwardf7edc0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7edc0::Forward() { return leaf_target(this); }
