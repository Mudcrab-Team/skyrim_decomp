// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf6a220, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf6a220 LeafForwardf6a220::Forward
#include "LeafForwardf6a220.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf6a220::Forward() { return leaf_target(this); }
