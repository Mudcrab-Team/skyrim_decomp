// Source exposure: binary-analysis
// Static97480, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97480;
extern void construct(Static97480*, const Descriptor*);
extern void destroy(Static97480*);
struct Static97480 {
    void* value;
    Static97480() { construct(this, &descriptor); }
    ~Static97480() { destroy(this); }
};
