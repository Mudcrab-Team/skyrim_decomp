// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1b410, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1b410 LeafForwardf1b410::Forward
#include "LeafForwardf1b410.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1b410::Forward() { return leaf_target(this); }
