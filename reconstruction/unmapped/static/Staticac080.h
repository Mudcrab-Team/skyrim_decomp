// Source exposure: binary-analysis
// Staticac080, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticac080;
extern void construct(Staticac080*, const Descriptor*);
extern void destroy(Staticac080*);
struct Staticac080 {
    void* value;
    Staticac080() { construct(this, &descriptor); }
    ~Staticac080() { destroy(this); }
};
