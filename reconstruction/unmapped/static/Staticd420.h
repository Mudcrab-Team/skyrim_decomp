// Source exposure: binary-analysis
// Staticd420, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd420;
extern void construct(Staticd420*, const Descriptor*);
extern void destroy(Staticd420*);
struct Staticd420 {
    void* value;
    Staticd420() { construct(this, &descriptor); }
    ~Staticd420() { destroy(this); }
};
