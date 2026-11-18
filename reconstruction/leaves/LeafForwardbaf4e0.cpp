// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbaf4e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbaf4e0 LeafForwardbaf4e0::Forward
#include "LeafForwardbaf4e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbaf4e0::Forward() { return leaf_target(this); }
