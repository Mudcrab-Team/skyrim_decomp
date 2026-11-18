// Source exposure: binary-analysis
// Statica6650, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6650;
extern void construct(Statica6650*, const Descriptor*);
extern void destroy(Statica6650*);
struct Statica6650 {
    void* value;
    Statica6650() { construct(this, &descriptor); }
    ~Statica6650() { destroy(this); }
};
