// Source exposure: binary-analysis; no external implementation reused.
// LeafForward122eb00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x122eb00 LeafForward122eb00::Forward
#include "LeafForward122eb00.h"
extern "C" void* leaf_target(void*);
void* LeafForward122eb00::Forward() { return leaf_target(this); }
