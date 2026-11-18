// Source exposure: binary-analysis
// Statica6d70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6d70;
extern void construct(Statica6d70*, const Descriptor*);
extern void destroy(Statica6d70*);
struct Statica6d70 {
    void* value;
    Statica6d70() { construct(this, &descriptor); }
    ~Statica6d70() { destroy(this); }
};
