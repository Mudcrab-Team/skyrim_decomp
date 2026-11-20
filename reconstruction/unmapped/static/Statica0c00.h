// Source exposure: binary-analysis
// Statica0c00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica0c00;
extern void construct(Statica0c00*, const Descriptor*);
extern void destroy(Statica0c00*);
struct Statica0c00 {
    void* value;
    Statica0c00() { construct(this, &descriptor); }
    ~Statica0c00() { destroy(this); }
};
