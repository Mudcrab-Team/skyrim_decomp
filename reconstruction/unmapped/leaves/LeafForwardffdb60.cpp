// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardffdb60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xffdb60 LeafForwardffdb60::Forward
#include "LeafForwardffdb60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardffdb60::Forward() { return leaf_target(this); }
