// Source exposure: binary-analysis; no external implementation reused.
// LeafForward109c040, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x109c040 LeafForward109c040::Forward
#include "LeafForward109c040.h"
extern "C" void* leaf_target(void*);
void* LeafForward109c040::Forward() { return leaf_target(this); }
