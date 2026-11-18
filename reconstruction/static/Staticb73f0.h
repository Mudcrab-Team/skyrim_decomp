// Source exposure: binary-analysis
// Staticb73f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb73f0;
extern void construct(Staticb73f0*, const Descriptor*);
extern void destroy(Staticb73f0*);
struct Staticb73f0 {
    void* value;
    Staticb73f0() { construct(this, &descriptor); }
    ~Staticb73f0() { destroy(this); }
};
