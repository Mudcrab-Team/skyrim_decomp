// Source exposure: binary-analysis
// Statica0a50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica0a50;
extern void construct(Statica0a50*, const Descriptor*);
extern void destroy(Statica0a50*);
struct Statica0a50 {
    void* value;
    Statica0a50() { construct(this, &descriptor); }
    ~Statica0a50() { destroy(this); }
};
