// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1135970, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1135970 LeafForward1135970::Forward
#include "LeafForward1135970.h"
extern "C" void* leaf_target(void*);
void* LeafForward1135970::Forward() { return leaf_target(this); }
