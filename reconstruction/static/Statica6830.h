// Source exposure: binary-analysis
// Statica6830, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6830;
extern void construct(Statica6830*, const Descriptor*);
extern void destroy(Statica6830*);
struct Statica6830 {
    void* value;
    Statica6830() { construct(this, &descriptor); }
    ~Statica6830() { destroy(this); }
};
