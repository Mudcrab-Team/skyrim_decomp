// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1000440, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1000440 LeafForward1000440::Forward
#include "LeafForward1000440.h"
extern "C" void* leaf_target(void*);
void* LeafForward1000440::Forward() { return leaf_target(this); }
