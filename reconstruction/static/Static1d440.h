// Source exposure: binary-analysis
// Static1d440, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1d440;
extern void construct(Static1d440*, const Descriptor*);
extern void destroy(Static1d440*);
struct Static1d440 {
    void* value;
    Static1d440() { construct(this, &descriptor); }
    ~Static1d440() { destroy(this); }
};
