// Source exposure: binary-analysis
// Static107fa0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static107fa0;
extern void construct(Static107fa0*, const Descriptor*);
extern void destroy(Static107fa0*);
struct Static107fa0 {
    void* value;
    Static107fa0() { construct(this, &descriptor); }
    ~Static107fa0() { destroy(this); }
};
