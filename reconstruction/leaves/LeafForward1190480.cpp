// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1190480, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1190480 LeafForward1190480::Forward
#include "LeafForward1190480.h"
extern "C" void* leaf_target(void*);
void* LeafForward1190480::Forward() { return leaf_target(this); }
