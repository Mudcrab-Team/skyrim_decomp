// Source exposure: binary-analysis
// Staticca280, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca280;
extern void construct(Staticca280*, const Descriptor*);
extern void destroy(Staticca280*);
struct Staticca280 {
    void* value;
    Staticca280() { construct(this, &descriptor); }
    ~Staticca280() { destroy(this); }
};
