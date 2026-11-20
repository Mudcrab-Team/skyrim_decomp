// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1f380, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1f380 LeafForwardf1f380::Forward
#include "LeafForwardf1f380.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1f380::Forward() { return leaf_target(this); }
