// Source exposure: binary-analysis
// Statica0c60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica0c60;
extern void construct(Statica0c60*, const Descriptor*);
extern void destroy(Statica0c60*);
struct Statica0c60 {
    void* value;
    Statica0c60() { construct(this, &descriptor); }
    ~Statica0c60() { destroy(this); }
};
