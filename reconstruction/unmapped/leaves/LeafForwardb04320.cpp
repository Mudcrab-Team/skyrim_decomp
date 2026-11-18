// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardb04320, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xb04320 LeafForwardb04320::Forward
#include "LeafForwardb04320.h"
extern "C" void* leaf_target(void*);
void* LeafForwardb04320::Forward() { return leaf_target(this); }
