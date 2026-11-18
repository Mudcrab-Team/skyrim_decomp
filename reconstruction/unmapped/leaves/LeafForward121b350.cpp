// Source exposure: binary-analysis; no external implementation reused.
// LeafForward121b350, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x121b350 LeafForward121b350::Forward
#include "LeafForward121b350.h"
extern "C" void* leaf_target(void*);
void* LeafForward121b350::Forward() { return leaf_target(this); }
