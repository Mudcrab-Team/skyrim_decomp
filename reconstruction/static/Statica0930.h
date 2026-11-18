// Source exposure: binary-analysis
// Statica0930, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica0930;
extern void construct(Statica0930*, const Descriptor*);
extern void destroy(Statica0930*);
struct Statica0930 {
    void* value;
    Statica0930() { construct(this, &descriptor); }
    ~Statica0930() { destroy(this); }
};
