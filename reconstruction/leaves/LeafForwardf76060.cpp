// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf76060, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf76060 LeafForwardf76060::Forward
#include "LeafForwardf76060.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf76060::Forward() { return leaf_target(this); }
