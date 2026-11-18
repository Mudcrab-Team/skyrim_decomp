// Source exposure: binary-analysis
// Statica6cb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6cb0;
extern void construct(Statica6cb0*, const Descriptor*);
extern void destroy(Statica6cb0*);
struct Statica6cb0 {
    void* value;
    Statica6cb0() { construct(this, &descriptor); }
    ~Statica6cb0() { destroy(this); }
};
