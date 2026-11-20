// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf739d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf739d0 LeafForwardf739d0::Forward
#include "LeafForwardf739d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf739d0::Forward() { return leaf_target(this); }
