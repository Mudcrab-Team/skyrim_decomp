// Source exposure: binary-analysis; no external implementation reused.
// LeafForward121b960, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x121b960 LeafForward121b960::Forward
#include "LeafForward121b960.h"
extern "C" void* leaf_target(void*);
void* LeafForward121b960::Forward() { return leaf_target(this); }
