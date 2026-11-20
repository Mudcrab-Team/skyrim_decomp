// Source exposure: binary-analysis; no external implementation reused.
// LeafForward78b510, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x78b510 LeafForward78b510::Forward
#include "LeafForward78b510.h"
extern "C" void* leaf_target(void*);
void* LeafForward78b510::Forward() { return leaf_target(this); }
