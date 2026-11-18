// Source exposure: binary-analysis
// Static23f00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static23f00;
extern void construct(Static23f00*, const Descriptor*);
extern void destroy(Static23f00*);
struct Static23f00 {
    void* value;
    Static23f00() { construct(this, &descriptor); }
    ~Static23f00() { destroy(this); }
};
