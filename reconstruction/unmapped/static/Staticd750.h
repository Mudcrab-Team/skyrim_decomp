// Source exposure: binary-analysis
// Staticd750, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd750;
extern void construct(Staticd750*, const Descriptor*);
extern void destroy(Staticd750*);
struct Staticd750 {
    void* value;
    Staticd750() { construct(this, &descriptor); }
    ~Staticd750() { destroy(this); }
};
