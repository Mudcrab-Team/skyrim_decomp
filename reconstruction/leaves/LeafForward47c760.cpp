// Source exposure: binary-analysis; no external implementation reused.
// LeafForward47c760, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x47c760 LeafForward47c760::Forward
#include "LeafForward47c760.h"
extern "C" void* leaf_target(void*);
void* LeafForward47c760::Forward() { return leaf_target(this); }
