// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf85330, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf85330 LeafForwardf85330::Forward
#include "LeafForwardf85330.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf85330::Forward() { return leaf_target(this); }
