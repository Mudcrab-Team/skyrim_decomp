// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf69070, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf69070 LeafForwardf69070::Forward
#include "LeafForwardf69070.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf69070::Forward() { return leaf_target(this); }
