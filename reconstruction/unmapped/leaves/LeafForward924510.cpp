// Source exposure: binary-analysis; no external implementation reused.
// LeafForward924510, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x924510 LeafForward924510::Forward
#include "LeafForward924510.h"
extern "C" void* leaf_target(void*);
void* LeafForward924510::Forward() { return leaf_target(this); }
