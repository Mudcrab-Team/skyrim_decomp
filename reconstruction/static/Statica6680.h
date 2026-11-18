// Source exposure: binary-analysis
// Statica6680, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6680;
extern void construct(Statica6680*, const Descriptor*);
extern void destroy(Statica6680*);
struct Statica6680 {
    void* value;
    Statica6680() { construct(this, &descriptor); }
    ~Statica6680() { destroy(this); }
};
