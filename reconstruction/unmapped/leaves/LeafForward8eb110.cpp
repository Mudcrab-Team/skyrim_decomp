// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8eb110, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8eb110 LeafForward8eb110::Forward
#include "LeafForward8eb110.h"
extern "C" void* leaf_target(void*);
void* LeafForward8eb110::Forward() { return leaf_target(this); }
