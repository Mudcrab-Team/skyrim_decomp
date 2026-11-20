// Source exposure: binary-analysis
// Static97bd0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97bd0;
extern void construct(Static97bd0*, const Descriptor*);
extern void destroy(Static97bd0*);
struct Static97bd0 {
    void* value;
    Static97bd0() { construct(this, &descriptor); }
    ~Static97bd0() { destroy(this); }
};
