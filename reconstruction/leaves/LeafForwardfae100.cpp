// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfae100, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfae100 LeafForwardfae100::Forward
#include "LeafForwardfae100.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfae100::Forward() { return leaf_target(this); }
