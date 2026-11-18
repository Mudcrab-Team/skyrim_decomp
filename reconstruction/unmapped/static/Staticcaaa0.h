// Source exposure: binary-analysis
// Staticcaaa0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticcaaa0;
extern void construct(Staticcaaa0*, const Descriptor*);
extern void destroy(Staticcaaa0*);
struct Staticcaaa0 {
    void* value;
    Staticcaaa0() { construct(this, &descriptor); }
    ~Staticcaaa0() { destroy(this); }
};
