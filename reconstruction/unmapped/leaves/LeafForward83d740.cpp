// Source exposure: binary-analysis; no external implementation reused.
// LeafForward83d740, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x83d740 LeafForward83d740::Forward
#include "LeafForward83d740.h"
extern "C" void* leaf_target(void*);
void* LeafForward83d740::Forward() { return leaf_target(this); }
