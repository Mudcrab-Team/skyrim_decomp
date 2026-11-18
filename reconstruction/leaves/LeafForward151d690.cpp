// Source exposure: binary-analysis; no external implementation reused.
// LeafForward151d690, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x151d690 LeafForward151d690::Forward
#include "LeafForward151d690.h"
extern "C" void* leaf_target(void*);
void* LeafForward151d690::Forward() { return leaf_target(this); }
