// Source exposure: binary-analysis; no external implementation reused.
// LeafForward888d20, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x888d20 LeafForward888d20::Forward
#include "LeafForward888d20.h"
extern "C" void* leaf_target(void*);
void* LeafForward888d20::Forward() { return leaf_target(this); }
