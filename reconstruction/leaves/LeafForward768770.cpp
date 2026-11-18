// Source exposure: binary-analysis; no external implementation reused.
// LeafForward768770, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x768770 LeafForward768770::Forward
#include "LeafForward768770.h"
extern "C" void* leaf_target(void*);
void* LeafForward768770::Forward() { return leaf_target(this); }
