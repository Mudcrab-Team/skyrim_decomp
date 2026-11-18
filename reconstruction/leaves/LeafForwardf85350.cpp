// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf85350, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf85350 LeafForwardf85350::Forward
#include "LeafForwardf85350.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf85350::Forward() { return leaf_target(this); }
