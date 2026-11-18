// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf9f730, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf9f730 LeafForwardf9f730::Forward
#include "LeafForwardf9f730.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf9f730::Forward() { return leaf_target(this); }
