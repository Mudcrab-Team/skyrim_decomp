// Source exposure: binary-analysis
// Statica6860, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6860;
extern void construct(Statica6860*, const Descriptor*);
extern void destroy(Statica6860*);
struct Statica6860 {
    void* value;
    Statica6860() { construct(this, &descriptor); }
    ~Statica6860() { destroy(this); }
};
