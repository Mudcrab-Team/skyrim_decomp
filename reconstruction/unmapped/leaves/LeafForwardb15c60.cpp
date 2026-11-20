// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardb15c60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xb15c60 LeafForwardb15c60::Forward
#include "LeafForwardb15c60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardb15c60::Forward() { return leaf_target(this); }
