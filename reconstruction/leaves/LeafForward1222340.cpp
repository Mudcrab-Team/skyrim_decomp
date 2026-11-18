// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1222340, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1222340 LeafForward1222340::Forward
#include "LeafForward1222340.h"
extern "C" void* leaf_target(void*);
void* LeafForward1222340::Forward() { return leaf_target(this); }
