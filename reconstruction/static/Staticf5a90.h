// Source exposure: binary-analysis
// Staticf5a90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf5a90;
extern void construct(Staticf5a90*, const Descriptor*);
extern void destroy(Staticf5a90*);
struct Staticf5a90 {
    void* value;
    Staticf5a90() { construct(this, &descriptor); }
    ~Staticf5a90() { destroy(this); }
};
