// Source exposure: binary-analysis
// Static23c00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static23c00;
extern void construct(Static23c00*, const Descriptor*);
extern void destroy(Static23c00*);
struct Static23c00 {
    void* value;
    Static23c00() { construct(this, &descriptor); }
    ~Static23c00() { destroy(this); }
};
