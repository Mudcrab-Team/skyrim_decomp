// Source exposure: binary-analysis
// Statica6560, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6560;
extern void construct(Statica6560*, const Descriptor*);
extern void destroy(Statica6560*);
struct Statica6560 {
    void* value;
    Statica6560() { construct(this, &descriptor); }
    ~Statica6560() { destroy(this); }
};
