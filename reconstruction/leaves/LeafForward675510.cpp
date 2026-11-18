// Source exposure: binary-analysis; no external implementation reused.
// LeafForward675510, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x675510 LeafForward675510::Forward
#include "LeafForward675510.h"
extern "C" void* leaf_target(void*);
void* LeafForward675510::Forward() { return leaf_target(this); }
