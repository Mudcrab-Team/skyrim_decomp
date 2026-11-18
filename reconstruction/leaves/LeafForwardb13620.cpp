// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardb13620, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xb13620 LeafForwardb13620::Forward
#include "LeafForwardb13620.h"
extern "C" void* leaf_target(void*);
void* LeafForwardb13620::Forward() { return leaf_target(this); }
