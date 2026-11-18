// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7d920, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7d920 LeafForwardf7d920::Forward
#include "LeafForwardf7d920.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7d920::Forward() { return leaf_target(this); }
