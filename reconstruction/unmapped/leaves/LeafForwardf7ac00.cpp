// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7ac00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7ac00 LeafForwardf7ac00::Forward
#include "LeafForwardf7ac00.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7ac00::Forward() { return leaf_target(this); }
