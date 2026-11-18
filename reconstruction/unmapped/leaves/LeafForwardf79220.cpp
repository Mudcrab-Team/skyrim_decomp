// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf79220, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf79220 LeafForwardf79220::Forward
#include "LeafForwardf79220.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf79220::Forward() { return leaf_target(this); }
