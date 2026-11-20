// Source exposure: binary-analysis
// Statica4230, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica4230;
extern void construct(Statica4230*, const Descriptor*);
extern void destroy(Statica4230*);
struct Statica4230 {
    void* value;
    Statica4230() { construct(this, &descriptor); }
    ~Statica4230() { destroy(this); }
};
