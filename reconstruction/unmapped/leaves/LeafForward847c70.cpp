// Source exposure: binary-analysis; no external implementation reused.
// LeafForward847c70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x847c70 LeafForward847c70::Forward
#include "LeafForward847c70.h"
extern "C" void* leaf_target(void*);
void* LeafForward847c70::Forward() { return leaf_target(this); }
