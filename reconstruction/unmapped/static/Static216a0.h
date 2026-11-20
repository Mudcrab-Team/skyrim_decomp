// Source exposure: binary-analysis
// Static216a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static216a0;
extern void construct(Static216a0*, const Descriptor*);
extern void destroy(Static216a0*);
struct Static216a0 {
    void* value;
    Static216a0() { construct(this, &descriptor); }
    ~Static216a0() { destroy(this); }
};
