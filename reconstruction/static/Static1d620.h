// Source exposure: binary-analysis
// Static1d620, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1d620;
extern void construct(Static1d620*, const Descriptor*);
extern void destroy(Static1d620*);
struct Static1d620 {
    void* value;
    Static1d620() { construct(this, &descriptor); }
    ~Static1d620() { destroy(this); }
};
