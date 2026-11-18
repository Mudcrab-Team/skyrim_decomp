// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf85570, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf85570 LeafForwardf85570::Forward
#include "LeafForwardf85570.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf85570::Forward() { return leaf_target(this); }
