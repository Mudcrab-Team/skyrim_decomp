// Source exposure: binary-analysis
// Statica2b20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica2b20;
extern void construct(Statica2b20*, const Descriptor*);
extern void destroy(Statica2b20*);
struct Statica2b20 {
    void* value;
    Statica2b20() { construct(this, &descriptor); }
    ~Statica2b20() { destroy(this); }
};
