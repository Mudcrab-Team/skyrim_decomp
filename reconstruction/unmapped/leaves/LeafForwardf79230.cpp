// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf79230, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf79230 LeafForwardf79230::Forward
#include "LeafForwardf79230.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf79230::Forward() { return leaf_target(this); }
