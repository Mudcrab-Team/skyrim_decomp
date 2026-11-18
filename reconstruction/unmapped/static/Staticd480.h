// Source exposure: binary-analysis
// Staticd480, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd480;
extern void construct(Staticd480*, const Descriptor*);
extern void destroy(Staticd480*);
struct Staticd480 {
    void* value;
    Staticd480() { construct(this, &descriptor); }
    ~Staticd480() { destroy(this); }
};
