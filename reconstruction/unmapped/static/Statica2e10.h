// Source exposure: binary-analysis
// Statica2e10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica2e10;
extern void construct(Statica2e10*, const Descriptor*);
extern void destroy(Statica2e10*);
struct Statica2e10 {
    void* value;
    Statica2e10() { construct(this, &descriptor); }
    ~Statica2e10() { destroy(this); }
};
