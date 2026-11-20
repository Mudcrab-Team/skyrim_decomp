// Source exposure: binary-analysis; no external implementation reused.
// LeafForward113ac50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x113ac50 LeafForward113ac50::Forward
#include "LeafForward113ac50.h"
extern "C" void* leaf_target(void*);
void* LeafForward113ac50::Forward() { return leaf_target(this); }
