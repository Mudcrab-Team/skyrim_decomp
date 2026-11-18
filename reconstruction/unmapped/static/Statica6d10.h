// Source exposure: binary-analysis
// Statica6d10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6d10;
extern void construct(Statica6d10*, const Descriptor*);
extern void destroy(Statica6d10*);
struct Statica6d10 {
    void* value;
    Statica6d10() { construct(this, &descriptor); }
    ~Statica6d10() { destroy(this); }
};
