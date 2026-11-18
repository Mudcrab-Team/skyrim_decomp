// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf79ae0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf79ae0 LeafForwardf79ae0::Forward
#include "LeafForwardf79ae0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf79ae0::Forward() { return leaf_target(this); }
