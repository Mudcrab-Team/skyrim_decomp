// Source exposure: binary-analysis
// Static21760, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21760;
extern void construct(Static21760*, const Descriptor*);
extern void destroy(Static21760*);
struct Static21760 {
    void* value;
    Static21760() { construct(this, &descriptor); }
    ~Static21760() { destroy(this); }
};
