// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf16280, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf16280 LeafForwardf16280::Forward
#include "LeafForwardf16280.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf16280::Forward() { return leaf_target(this); }
