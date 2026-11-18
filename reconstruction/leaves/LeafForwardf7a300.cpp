// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7a300, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7a300 LeafForwardf7a300::Forward
#include "LeafForwardf7a300.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7a300::Forward() { return leaf_target(this); }
