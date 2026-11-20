// Source exposure: binary-analysis
// Static97540, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97540;
extern void construct(Static97540*, const Descriptor*);
extern void destroy(Static97540*);
struct Static97540 {
    void* value;
    Static97540() { construct(this, &descriptor); }
    ~Static97540() { destroy(this); }
};
