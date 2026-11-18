// Source exposure: binary-analysis
// Staticd270, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd270;
extern void construct(Staticd270*, const Descriptor*);
extern void destroy(Staticd270*);
struct Staticd270 {
    void* value;
    Staticd270() { construct(this, &descriptor); }
    ~Staticd270() { destroy(this); }
};
