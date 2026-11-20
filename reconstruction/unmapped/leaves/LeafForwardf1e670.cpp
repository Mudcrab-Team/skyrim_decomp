// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1e670, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1e670 LeafForwardf1e670::Forward
#include "LeafForwardf1e670.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1e670::Forward() { return leaf_target(this); }
