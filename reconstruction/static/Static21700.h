// Source exposure: binary-analysis
// Static21700, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21700;
extern void construct(Static21700*, const Descriptor*);
extern void destroy(Static21700*);
struct Static21700 {
    void* value;
    Static21700() { construct(this, &descriptor); }
    ~Static21700() { destroy(this); }
};
