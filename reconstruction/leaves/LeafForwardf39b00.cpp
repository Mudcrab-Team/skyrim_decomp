// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf39b00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf39b00 LeafForwardf39b00::Forward
#include "LeafForwardf39b00.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf39b00::Forward() { return leaf_target(this); }
