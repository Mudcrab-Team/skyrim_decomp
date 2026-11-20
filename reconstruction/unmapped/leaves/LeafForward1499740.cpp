// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1499740, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1499740 LeafForward1499740::Forward
#include "LeafForward1499740.h"
extern "C" void* leaf_target(void*);
void* LeafForward1499740::Forward() { return leaf_target(this); }
