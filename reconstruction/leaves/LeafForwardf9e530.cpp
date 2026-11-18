// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf9e530, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf9e530 LeafForwardf9e530::Forward
#include "LeafForwardf9e530.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf9e530::Forward() { return leaf_target(this); }
