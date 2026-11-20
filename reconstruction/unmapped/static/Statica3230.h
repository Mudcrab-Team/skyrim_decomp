// Source exposure: binary-analysis
// Statica3230, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica3230;
extern void construct(Statica3230*, const Descriptor*);
extern void destroy(Statica3230*);
struct Statica3230 {
    void* value;
    Statica3230() { construct(this, &descriptor); }
    ~Statica3230() { destroy(this); }
};
