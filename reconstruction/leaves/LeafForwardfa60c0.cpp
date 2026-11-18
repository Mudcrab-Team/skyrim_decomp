// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa60c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa60c0 LeafForwardfa60c0::Forward
#include "LeafForwardfa60c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa60c0::Forward() { return leaf_target(this); }
