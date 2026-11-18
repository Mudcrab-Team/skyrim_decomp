// Source exposure: binary-analysis; no external implementation reused.
// LeafForward845810, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x845810 LeafForward845810::Forward
#include "LeafForward845810.h"
extern "C" void* leaf_target(void*);
void* LeafForward845810::Forward() { return leaf_target(this); }
