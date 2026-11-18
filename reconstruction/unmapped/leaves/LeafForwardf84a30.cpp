// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf84a30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf84a30 LeafForwardf84a30::Forward
#include "LeafForwardf84a30.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf84a30::Forward() { return leaf_target(this); }
