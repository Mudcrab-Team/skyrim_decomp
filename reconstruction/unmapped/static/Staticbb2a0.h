// Source exposure: binary-analysis
// Staticbb2a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbb2a0;
extern void construct(Staticbb2a0*, const Descriptor*);
extern void destroy(Staticbb2a0*);
struct Staticbb2a0 {
    void* value;
    Staticbb2a0() { construct(this, &descriptor); }
    ~Staticbb2a0() { destroy(this); }
};
