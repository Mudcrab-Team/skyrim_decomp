// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1dfc20, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1dfc20 LeafForward1dfc20::Forward
#include "LeafForward1dfc20.h"
extern "C" void* leaf_target(void*);
void* LeafForward1dfc20::Forward() { return leaf_target(this); }
