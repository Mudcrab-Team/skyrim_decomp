// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfe5300, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfe5300 LeafForwardfe5300::Forward
#include "LeafForwardfe5300.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfe5300::Forward() { return leaf_target(this); }
