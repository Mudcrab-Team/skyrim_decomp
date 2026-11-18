// Source exposure: binary-analysis
// Statica09f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica09f0;
extern void construct(Statica09f0*, const Descriptor*);
extern void destroy(Statica09f0*);
struct Statica09f0 {
    void* value;
    Statica09f0() { construct(this, &descriptor); }
    ~Statica09f0() { destroy(this); }
};
