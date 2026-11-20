// Source exposure: binary-analysis
// Statica3050, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica3050;
extern void construct(Statica3050*, const Descriptor*);
extern void destroy(Statica3050*);
struct Statica3050 {
    void* value;
    Statica3050() { construct(this, &descriptor); }
    ~Statica3050() { destroy(this); }
};
