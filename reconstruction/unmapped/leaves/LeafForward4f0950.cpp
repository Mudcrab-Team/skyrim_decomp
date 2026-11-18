// Source exposure: binary-analysis; no external implementation reused.
// LeafForward4f0950, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x4f0950 LeafForward4f0950::Forward
#include "LeafForward4f0950.h"
extern "C" void* leaf_target(void*);
void* LeafForward4f0950::Forward() { return leaf_target(this); }
