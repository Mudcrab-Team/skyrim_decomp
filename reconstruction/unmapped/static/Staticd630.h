// Source exposure: binary-analysis
// Staticd630, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd630;
extern void construct(Staticd630*, const Descriptor*);
extern void destroy(Staticd630*);
struct Staticd630 {
    void* value;
    Staticd630() { construct(this, &descriptor); }
    ~Staticd630() { destroy(this); }
};
