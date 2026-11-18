// Source exposure: binary-analysis
// Static157c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static157c0;
extern void construct(Static157c0*, const Descriptor*);
extern void destroy(Static157c0*);
struct Static157c0 {
    void* value;
    Static157c0() { construct(this, &descriptor); }
    ~Static157c0() { destroy(this); }
};
