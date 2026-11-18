// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf97c00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf97c00 LeafForwardf97c00::Forward
#include "LeafForwardf97c00.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf97c00::Forward() { return leaf_target(this); }
