// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1221230, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1221230 LeafForward1221230::Forward
#include "LeafForward1221230.h"
extern "C" void* leaf_target(void*);
void* LeafForward1221230::Forward() { return leaf_target(this); }
