// Source exposure: binary-analysis
// Static15700, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15700;
extern void construct(Static15700*, const Descriptor*);
extern void destroy(Static15700*);
struct Static15700 {
    void* value;
    Static15700() { construct(this, &descriptor); }
    ~Static15700() { destroy(this); }
};
