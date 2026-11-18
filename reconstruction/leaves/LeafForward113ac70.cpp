// Source exposure: binary-analysis; no external implementation reused.
// LeafForward113ac70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x113ac70 LeafForward113ac70::Forward
#include "LeafForward113ac70.h"
extern "C" void* leaf_target(void*);
void* LeafForward113ac70::Forward() { return leaf_target(this); }
