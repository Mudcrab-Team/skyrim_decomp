// Source exposure: binary-analysis; no external implementation reused.
// LeafForward907280, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x907280 LeafForward907280::Forward
#include "LeafForward907280.h"
extern "C" void* leaf_target(void*);
void* LeafForward907280::Forward() { return leaf_target(this); }
