// Source exposure: binary-analysis; no external implementation reused.
// LeafForward9ed260, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x9ed260 LeafForward9ed260::Forward
#include "LeafForward9ed260.h"
extern "C" void* leaf_target(void*);
void* LeafForward9ed260::Forward() { return leaf_target(this); }
