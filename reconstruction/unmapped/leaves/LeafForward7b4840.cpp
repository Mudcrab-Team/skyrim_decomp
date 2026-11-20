// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7b4840, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7b4840 LeafForward7b4840::Forward
#include "LeafForward7b4840.h"
extern "C" void* leaf_target(void*);
void* LeafForward7b4840::Forward() { return leaf_target(this); }
