// Source exposure: binary-analysis; no external implementation reused.
// LeafForward9ecf10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x9ecf10 LeafForward9ecf10::Forward
#include "LeafForward9ecf10.h"
extern "C" void* leaf_target(void*);
void* LeafForward9ecf10::Forward() { return leaf_target(this); }
