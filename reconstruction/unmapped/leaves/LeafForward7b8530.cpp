// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7b8530, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7b8530 LeafForward7b8530::Forward
#include "LeafForward7b8530.h"
extern "C" void* leaf_target(void*);
void* LeafForward7b8530::Forward() { return leaf_target(this); }
