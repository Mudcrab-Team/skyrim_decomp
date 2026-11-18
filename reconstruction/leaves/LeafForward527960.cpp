// Source exposure: binary-analysis; no external implementation reused.
// LeafForward527960, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x527960 LeafForward527960::Forward
#include "LeafForward527960.h"
extern "C" void* leaf_target(void*);
void* LeafForward527960::Forward() { return leaf_target(this); }
