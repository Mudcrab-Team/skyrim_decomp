// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf6ae30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf6ae30 LeafForwardf6ae30::Forward
#include "LeafForwardf6ae30.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf6ae30::Forward() { return leaf_target(this); }
