// Source exposure: binary-analysis
// Statica0e50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica0e50;
extern void construct(Statica0e50*, const Descriptor*);
extern void destroy(Statica0e50*);
struct Statica0e50 {
    void* value;
    Statica0e50() { construct(this, &descriptor); }
    ~Statica0e50() { destroy(this); }
};
