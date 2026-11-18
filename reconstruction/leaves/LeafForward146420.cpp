// Source exposure: binary-analysis; no external implementation reused.
// LeafForward146420, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x146420 LeafForward146420::Forward
#include "LeafForward146420.h"
extern "C" void* leaf_target(void*);
void* LeafForward146420::Forward() { return leaf_target(this); }
