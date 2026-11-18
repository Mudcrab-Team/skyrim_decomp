// Source exposure: binary-analysis
// Statica6500, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6500;
extern void construct(Statica6500*, const Descriptor*);
extern void destroy(Statica6500*);
struct Statica6500 {
    void* value;
    Statica6500() { construct(this, &descriptor); }
    ~Statica6500() { destroy(this); }
};
