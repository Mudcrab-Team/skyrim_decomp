// Source exposure: binary-analysis; no external implementation reused.
// LeafForward156fd60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x156fd60 LeafForward156fd60::Forward
#include "LeafForward156fd60.h"
extern "C" void* leaf_target(void*);
void* LeafForward156fd60::Forward() { return leaf_target(this); }
