// Source exposure: binary-analysis
// Statica0d50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica0d50;
extern void construct(Statica0d50*, const Descriptor*);
extern void destroy(Statica0d50*);
struct Statica0d50 {
    void* value;
    Statica0d50() { construct(this, &descriptor); }
    ~Statica0d50() { destroy(this); }
};
