// Source exposure: binary-analysis
// Static1b190, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b190;
extern void construct(Static1b190*, const Descriptor*);
extern void destroy(Static1b190*);
struct Static1b190 {
    void* value;
    Static1b190() { construct(this, &descriptor); }
    ~Static1b190() { destroy(this); }
};
