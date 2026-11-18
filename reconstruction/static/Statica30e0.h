// Source exposure: binary-analysis
// Statica30e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica30e0;
extern void construct(Statica30e0*, const Descriptor*);
extern void destroy(Statica30e0*);
struct Statica30e0 {
    void* value;
    Statica30e0() { construct(this, &descriptor); }
    ~Statica30e0() { destroy(this); }
};
