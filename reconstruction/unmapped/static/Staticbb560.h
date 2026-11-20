// Source exposure: binary-analysis
// Staticbb560, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbb560;
extern void construct(Staticbb560*, const Descriptor*);
extern void destroy(Staticbb560*);
struct Staticbb560 {
    void* value;
    Staticbb560() { construct(this, &descriptor); }
    ~Staticbb560() { destroy(this); }
};
