// Source exposure: binary-analysis; no external implementation reused.
// LeafForward121dc70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x121dc70 LeafForward121dc70::Forward
#include "LeafForward121dc70.h"
extern "C" void* leaf_target(void*);
void* LeafForward121dc70::Forward() { return leaf_target(this); }
