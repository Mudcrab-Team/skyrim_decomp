// Source exposure: binary-analysis
// Statica6950, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6950;
extern void construct(Statica6950*, const Descriptor*);
extern void destroy(Statica6950*);
struct Statica6950 {
    void* value;
    Statica6950() { construct(this, &descriptor); }
    ~Statica6950() { destroy(this); }
};
