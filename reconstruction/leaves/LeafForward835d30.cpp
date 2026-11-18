// Source exposure: binary-analysis; no external implementation reused.
// LeafForward835d30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x835d30 LeafForward835d30::Forward
#include "LeafForward835d30.h"
extern "C" void* leaf_target(void*);
void* LeafForward835d30::Forward() { return leaf_target(this); }
