// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf0f280, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf0f280 LeafForwardf0f280::Forward
#include "LeafForwardf0f280.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf0f280::Forward() { return leaf_target(this); }
