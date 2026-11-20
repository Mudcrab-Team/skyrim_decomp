// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf67c00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf67c00 LeafForwardf67c00::Forward
#include "LeafForwardf67c00.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf67c00::Forward() { return leaf_target(this); }
