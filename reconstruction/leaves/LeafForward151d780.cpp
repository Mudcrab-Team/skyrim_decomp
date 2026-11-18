// Source exposure: binary-analysis; no external implementation reused.
// LeafForward151d780, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x151d780 LeafForward151d780::Forward
#include "LeafForward151d780.h"
extern "C" void* leaf_target(void*);
void* LeafForward151d780::Forward() { return leaf_target(this); }
