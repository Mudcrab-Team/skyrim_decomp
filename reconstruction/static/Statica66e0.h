// Source exposure: binary-analysis
// Statica66e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica66e0;
extern void construct(Statica66e0*, const Descriptor*);
extern void destroy(Statica66e0*);
struct Statica66e0 {
    void* value;
    Statica66e0() { construct(this, &descriptor); }
    ~Statica66e0() { destroy(this); }
};
