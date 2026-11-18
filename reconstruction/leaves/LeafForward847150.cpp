// Source exposure: binary-analysis; no external implementation reused.
// LeafForward847150, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x847150 LeafForward847150::Forward
#include "LeafForward847150.h"
extern "C" void* leaf_target(void*);
void* LeafForward847150::Forward() { return leaf_target(this); }
