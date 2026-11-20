// Source exposure: binary-analysis
// Statica3080, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica3080;
extern void construct(Statica3080*, const Descriptor*);
extern void destroy(Statica3080*);
struct Statica3080 {
    void* value;
    Statica3080() { construct(this, &descriptor); }
    ~Statica3080() { destroy(this); }
};
