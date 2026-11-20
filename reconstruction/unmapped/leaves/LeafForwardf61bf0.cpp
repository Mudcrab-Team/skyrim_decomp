// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf61bf0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf61bf0 LeafForwardf61bf0::Forward
#include "LeafForwardf61bf0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf61bf0::Forward() { return leaf_target(this); }
