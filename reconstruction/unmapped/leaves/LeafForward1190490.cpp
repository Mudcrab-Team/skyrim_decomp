// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1190490, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1190490 LeafForward1190490::Forward
#include "LeafForward1190490.h"
extern "C" void* leaf_target(void*);
void* LeafForward1190490::Forward() { return leaf_target(this); }
