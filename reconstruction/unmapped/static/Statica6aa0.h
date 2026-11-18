// Source exposure: binary-analysis
// Statica6aa0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6aa0;
extern void construct(Statica6aa0*, const Descriptor*);
extern void destroy(Statica6aa0*);
struct Statica6aa0 {
    void* value;
    Statica6aa0() { construct(this, &descriptor); }
    ~Statica6aa0() { destroy(this); }
};
