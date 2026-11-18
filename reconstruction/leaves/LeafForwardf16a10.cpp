// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf16a10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf16a10 LeafForwardf16a10::Forward
#include "LeafForwardf16a10.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf16a10::Forward() { return leaf_target(this); }
