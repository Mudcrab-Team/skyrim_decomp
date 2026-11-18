// Source exposure: binary-analysis
// Statica4560, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica4560;
extern void construct(Statica4560*, const Descriptor*);
extern void destroy(Statica4560*);
struct Statica4560 {
    void* value;
    Statica4560() { construct(this, &descriptor); }
    ~Statica4560() { destroy(this); }
};
