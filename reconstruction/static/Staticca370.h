// Source exposure: binary-analysis
// Staticca370, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca370;
extern void construct(Staticca370*, const Descriptor*);
extern void destroy(Staticca370*);
struct Staticca370 {
    void* value;
    Staticca370() { construct(this, &descriptor); }
    ~Staticca370() { destroy(this); }
};
