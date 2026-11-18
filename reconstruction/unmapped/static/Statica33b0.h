// Source exposure: binary-analysis
// Statica33b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica33b0;
extern void construct(Statica33b0*, const Descriptor*);
extern void destroy(Statica33b0*);
struct Statica33b0 {
    void* value;
    Statica33b0() { construct(this, &descriptor); }
    ~Statica33b0() { destroy(this); }
};
