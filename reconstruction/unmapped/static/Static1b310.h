// Source exposure: binary-analysis
// Static1b310, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b310;
extern void construct(Static1b310*, const Descriptor*);
extern void destroy(Static1b310*);
struct Static1b310 {
    void* value;
    Static1b310() { construct(this, &descriptor); }
    ~Static1b310() { destroy(this); }
};
