// Source exposure: binary-analysis; no external implementation reused.
// LeafForward82b550, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x82b550 LeafForward82b550::Forward
#include "LeafForward82b550.h"
extern "C" void* leaf_target(void*);
void* LeafForward82b550::Forward() { return leaf_target(this); }
