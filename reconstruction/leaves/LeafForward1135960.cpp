// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1135960, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1135960 LeafForward1135960::Forward
#include "LeafForward1135960.h"
extern "C" void* leaf_target(void*);
void* LeafForward1135960::Forward() { return leaf_target(this); }
