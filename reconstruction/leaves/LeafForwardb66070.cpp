// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardb66070, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xb66070 LeafForwardb66070::Forward
#include "LeafForwardb66070.h"
extern "C" void* leaf_target(void*);
void* LeafForwardb66070::Forward() { return leaf_target(this); }
