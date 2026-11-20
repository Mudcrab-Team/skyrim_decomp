// Source exposure: binary-analysis; no external implementation reused.
// LeafForward192870, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x192870 LeafForward192870::Forward
#include "LeafForward192870.h"
extern "C" void* leaf_target(void*);
void* LeafForward192870::Forward() { return leaf_target(this); }
