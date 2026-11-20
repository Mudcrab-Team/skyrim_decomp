// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb9420, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb9420 LeafForwardfb9420::Forward
#include "LeafForwardfb9420.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb9420::Forward() { return leaf_target(this); }
