// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf10a50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf10a50 LeafForwardf10a50::Forward
#include "LeafForwardf10a50.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf10a50::Forward() { return leaf_target(this); }
