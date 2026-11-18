// Source exposure: binary-analysis
// Staticef730, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticef730;
extern void construct(Staticef730*, const Descriptor*);
extern void destroy(Staticef730*);
struct Staticef730 {
    void* value;
    Staticef730() { construct(this, &descriptor); }
    ~Staticef730() { destroy(this); }
};
