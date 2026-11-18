// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf74e00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf74e00 LeafForwardf74e00::Forward
#include "LeafForwardf74e00.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf74e00::Forward() { return leaf_target(this); }
