// Source exposure: binary-analysis; no external implementation reused.
// LeafForward477560, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x477560 LeafForward477560::Forward
#include "LeafForward477560.h"
extern "C" void* leaf_target(void*);
void* LeafForward477560::Forward() { return leaf_target(this); }
