// Source exposure: binary-analysis; no external implementation reused.
// LeafForward149510, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x149510 LeafForward149510::Forward
#include "LeafForward149510.h"
extern "C" void* leaf_target(void*);
void* LeafForward149510::Forward() { return leaf_target(this); }
