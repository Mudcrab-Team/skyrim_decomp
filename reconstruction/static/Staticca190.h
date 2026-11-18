// Source exposure: binary-analysis
// Staticca190, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca190;
extern void construct(Staticca190*, const Descriptor*);
extern void destroy(Staticca190*);
struct Staticca190 {
    void* value;
    Staticca190() { construct(this, &descriptor); }
    ~Staticca190() { destroy(this); }
};
