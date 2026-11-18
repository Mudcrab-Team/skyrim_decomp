// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1529780, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1529780 LeafForward1529780::Forward
#include "LeafForward1529780.h"
extern "C" void* leaf_target(void*);
void* LeafForward1529780::Forward() { return leaf_target(this); }
