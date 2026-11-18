// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf98780, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf98780 LeafForwardf98780::Forward
#include "LeafForwardf98780.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf98780::Forward() { return leaf_target(this); }
