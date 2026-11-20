// Source exposure: binary-analysis; no external implementation reused.
// LeafForward83d190, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x83d190 LeafForward83d190::Forward
#include "LeafForward83d190.h"
extern "C" void* leaf_target(void*);
void* LeafForward83d190::Forward() { return leaf_target(this); }
