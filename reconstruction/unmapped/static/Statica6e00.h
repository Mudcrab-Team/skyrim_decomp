// Source exposure: binary-analysis
// Statica6e00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6e00;
extern void construct(Statica6e00*, const Descriptor*);
extern void destroy(Statica6e00*);
struct Statica6e00 {
    void* value;
    Statica6e00() { construct(this, &descriptor); }
    ~Statica6e00() { destroy(this); }
};
