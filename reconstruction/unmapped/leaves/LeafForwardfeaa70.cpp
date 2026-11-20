// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfeaa70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfeaa70 LeafForwardfeaa70::Forward
#include "LeafForwardfeaa70.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfeaa70::Forward() { return leaf_target(this); }
