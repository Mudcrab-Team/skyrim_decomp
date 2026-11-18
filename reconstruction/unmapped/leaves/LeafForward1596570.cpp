// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1596570, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1596570 LeafForward1596570::Forward
#include "LeafForward1596570.h"
extern "C" void* leaf_target(void*);
void* LeafForward1596570::Forward() { return leaf_target(this); }
