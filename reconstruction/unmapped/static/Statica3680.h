// Source exposure: binary-analysis
// Statica3680, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica3680;
extern void construct(Statica3680*, const Descriptor*);
extern void destroy(Statica3680*);
struct Statica3680 {
    void* value;
    Statica3680() { construct(this, &descriptor); }
    ~Statica3680() { destroy(this); }
};
