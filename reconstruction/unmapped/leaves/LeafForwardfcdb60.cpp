// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfcdb60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfcdb60 LeafForwardfcdb60::Forward
#include "LeafForwardfcdb60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfcdb60::Forward() { return leaf_target(this); }
