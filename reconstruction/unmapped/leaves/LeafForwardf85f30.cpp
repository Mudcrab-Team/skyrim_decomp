// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf85f30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf85f30 LeafForwardf85f30::Forward
#include "LeafForwardf85f30.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf85f30::Forward() { return leaf_target(this); }
