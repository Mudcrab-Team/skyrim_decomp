// Source exposure: binary-analysis
// Staticd570, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd570;
extern void construct(Staticd570*, const Descriptor*);
extern void destroy(Staticd570*);
struct Staticd570 {
    void* value;
    Staticd570() { construct(this, &descriptor); }
    ~Staticd570() { destroy(this); }
};
