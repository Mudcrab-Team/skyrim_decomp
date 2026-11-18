// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1061740, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1061740 LeafForward1061740::Forward
#include "LeafForward1061740.h"
extern "C" void* leaf_target(void*);
void* LeafForward1061740::Forward() { return leaf_target(this); }
