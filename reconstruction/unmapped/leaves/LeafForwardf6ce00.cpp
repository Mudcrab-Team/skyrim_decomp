// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf6ce00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf6ce00 LeafForwardf6ce00::Forward
#include "LeafForwardf6ce00.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf6ce00::Forward() { return leaf_target(this); }
