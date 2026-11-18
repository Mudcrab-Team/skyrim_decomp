// Source exposure: binary-analysis
// Static97870, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97870;
extern void construct(Static97870*, const Descriptor*);
extern void destroy(Static97870*);
struct Static97870 {
    void* value;
    Static97870() { construct(this, &descriptor); }
    ~Static97870() { destroy(this); }
};
