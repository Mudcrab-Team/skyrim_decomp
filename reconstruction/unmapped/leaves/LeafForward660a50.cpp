// Source exposure: binary-analysis; no external implementation reused.
// LeafForward660a50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x660a50 LeafForward660a50::Forward
#include "LeafForward660a50.h"
extern "C" void* leaf_target(void*);
void* LeafForward660a50::Forward() { return leaf_target(this); }
