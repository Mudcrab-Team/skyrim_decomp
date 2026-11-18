// Source exposure: binary-analysis
// Static1def0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1def0;
extern void construct(Static1def0*, const Descriptor*);
extern void destroy(Static1def0*);
struct Static1def0 {
    void* value;
    Static1def0() { construct(this, &descriptor); }
    ~Static1def0() { destroy(this); }
};
