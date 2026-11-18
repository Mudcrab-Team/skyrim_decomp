// Source exposure: binary-analysis
// Staticf3010, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf3010;
extern void construct(Staticf3010*, const Descriptor*);
extern void destroy(Staticf3010*);
struct Staticf3010 {
    void* value;
    Staticf3010() { construct(this, &descriptor); }
    ~Staticf3010() { destroy(this); }
};
