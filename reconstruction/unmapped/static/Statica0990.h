// Source exposure: binary-analysis
// Statica0990, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica0990;
extern void construct(Statica0990*, const Descriptor*);
extern void destroy(Statica0990*);
struct Statica0990 {
    void* value;
    Statica0990() { construct(this, &descriptor); }
    ~Statica0990() { destroy(this); }
};
