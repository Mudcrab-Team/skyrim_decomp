// Source exposure: binary-analysis; no external implementation reused.
// LeafForward9ed930, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x9ed930 LeafForward9ed930::Forward
#include "LeafForward9ed930.h"
extern "C" void* leaf_target(void*);
void* LeafForward9ed930::Forward() { return leaf_target(this); }
