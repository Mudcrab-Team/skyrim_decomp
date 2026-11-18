// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardb052d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xb052d0 LeafForwardb052d0::Forward
#include "LeafForwardb052d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardb052d0::Forward() { return leaf_target(this); }
