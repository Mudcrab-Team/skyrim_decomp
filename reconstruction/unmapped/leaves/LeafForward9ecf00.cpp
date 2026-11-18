// Source exposure: binary-analysis; no external implementation reused.
// LeafForward9ecf00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x9ecf00 LeafForward9ecf00::Forward
#include "LeafForward9ecf00.h"
extern "C" void* leaf_target(void*);
void* LeafForward9ecf00::Forward() { return leaf_target(this); }
