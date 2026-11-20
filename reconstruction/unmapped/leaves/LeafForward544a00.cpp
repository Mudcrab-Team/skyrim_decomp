// Source exposure: binary-analysis; no external implementation reused.
// LeafForward544a00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x544a00 LeafForward544a00::Forward
#include "LeafForward544a00.h"
extern "C" void* leaf_target(void*);
void* LeafForward544a00::Forward() { return leaf_target(this); }
