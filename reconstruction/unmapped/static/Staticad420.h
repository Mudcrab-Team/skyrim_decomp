// Source exposure: binary-analysis
// Staticad420, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticad420;
extern void construct(Staticad420*, const Descriptor*);
extern void destroy(Staticad420*);
struct Staticad420 {
    void* value;
    Staticad420() { construct(this, &descriptor); }
    ~Staticad420() { destroy(this); }
};
