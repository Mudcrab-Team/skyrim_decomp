// Source exposure: binary-analysis; no external implementation reused.
// LeafForward133e170, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x133e170 LeafForward133e170::Forward
#include "LeafForward133e170.h"
extern "C" void* leaf_target(void*);
void* LeafForward133e170::Forward() { return leaf_target(this); }
