// Source exposure: binary-analysis; no external implementation reused.
// LeafForward844330, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x844330 LeafForward844330::Forward
#include "LeafForward844330.h"
extern "C" void* leaf_target(void*);
void* LeafForward844330::Forward() { return leaf_target(this); }
