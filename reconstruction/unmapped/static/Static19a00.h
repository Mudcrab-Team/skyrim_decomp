// Source exposure: binary-analysis
// Static19a00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static19a00;
extern void construct(Static19a00*, const Descriptor*);
extern void destroy(Static19a00*);
struct Static19a00 {
    void* value;
    Static19a00() { construct(this, &descriptor); }
    ~Static19a00() { destroy(this); }
};
