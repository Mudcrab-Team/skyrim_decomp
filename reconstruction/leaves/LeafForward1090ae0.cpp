// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1090ae0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1090ae0 LeafForward1090ae0::Forward
#include "LeafForward1090ae0.h"
extern "C" void* leaf_target(void*);
void* LeafForward1090ae0::Forward() { return leaf_target(this); }
