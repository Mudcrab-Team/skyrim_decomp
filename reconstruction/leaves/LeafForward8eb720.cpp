// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8eb720, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8eb720 LeafForward8eb720::Forward
#include "LeafForward8eb720.h"
extern "C" void* leaf_target(void*);
void* LeafForward8eb720::Forward() { return leaf_target(this); }
