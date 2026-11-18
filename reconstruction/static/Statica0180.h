// Source exposure: binary-analysis
// Statica0180, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica0180;
extern void construct(Statica0180*, const Descriptor*);
extern void destroy(Statica0180*);
struct Statica0180 {
    void* value;
    Statica0180() { construct(this, &descriptor); }
    ~Statica0180() { destroy(this); }
};
