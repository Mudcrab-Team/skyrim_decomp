// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardb1b740, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xb1b740 LeafForwardb1b740::Forward
#include "LeafForwardb1b740.h"
extern "C" void* leaf_target(void*);
void* LeafForwardb1b740::Forward() { return leaf_target(this); }
