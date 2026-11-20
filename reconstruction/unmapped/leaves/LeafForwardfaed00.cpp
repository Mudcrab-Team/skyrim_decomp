// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfaed00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfaed00 LeafForwardfaed00::Forward
#include "LeafForwardfaed00.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfaed00::Forward() { return leaf_target(this); }
