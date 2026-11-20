// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1573e00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1573e00 LeafForward1573e00::Forward
#include "LeafForward1573e00.h"
extern "C" void* leaf_target(void*);
void* LeafForward1573e00::Forward() { return leaf_target(this); }
