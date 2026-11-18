// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardc4c460, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xc4c460 LeafForwardc4c460::Forward
#include "LeafForwardc4c460.h"
extern "C" void* leaf_target(void*);
void* LeafForwardc4c460::Forward() { return leaf_target(this); }
