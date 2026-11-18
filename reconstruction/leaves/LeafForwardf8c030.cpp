// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf8c030, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf8c030 LeafForwardf8c030::Forward
#include "LeafForwardf8c030.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf8c030::Forward() { return leaf_target(this); }
