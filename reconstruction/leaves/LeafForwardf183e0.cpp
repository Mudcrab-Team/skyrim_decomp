// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf183e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf183e0 LeafForwardf183e0::Forward
#include "LeafForwardf183e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf183e0::Forward() { return leaf_target(this); }
