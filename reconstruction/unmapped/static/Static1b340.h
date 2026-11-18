// Source exposure: binary-analysis
// Static1b340, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b340;
extern void construct(Static1b340*, const Descriptor*);
extern void destroy(Static1b340*);
struct Static1b340 {
    void* value;
    Static1b340() { construct(this, &descriptor); }
    ~Static1b340() { destroy(this); }
};
