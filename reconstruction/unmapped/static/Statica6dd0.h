// Source exposure: binary-analysis
// Statica6dd0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6dd0;
extern void construct(Statica6dd0*, const Descriptor*);
extern void destroy(Statica6dd0*);
struct Statica6dd0 {
    void* value;
    Statica6dd0() { construct(this, &descriptor); }
    ~Statica6dd0() { destroy(this); }
};
