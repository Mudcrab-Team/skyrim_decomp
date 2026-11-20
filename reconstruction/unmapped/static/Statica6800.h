// Source exposure: binary-analysis
// Statica6800, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6800;
extern void construct(Statica6800*, const Descriptor*);
extern void destroy(Statica6800*);
struct Statica6800 {
    void* value;
    Statica6800() { construct(this, &descriptor); }
    ~Statica6800() { destroy(this); }
};
