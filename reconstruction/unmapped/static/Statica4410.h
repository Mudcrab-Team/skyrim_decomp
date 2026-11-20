// Source exposure: binary-analysis
// Statica4410, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica4410;
extern void construct(Statica4410*, const Descriptor*);
extern void destroy(Statica4410*);
struct Statica4410 {
    void* value;
    Statica4410() { construct(this, &descriptor); }
    ~Statica4410() { destroy(this); }
};
