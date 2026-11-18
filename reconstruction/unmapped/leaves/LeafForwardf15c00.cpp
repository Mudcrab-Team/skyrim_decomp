// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf15c00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf15c00 LeafForwardf15c00::Forward
#include "LeafForwardf15c00.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf15c00::Forward() { return leaf_target(this); }
