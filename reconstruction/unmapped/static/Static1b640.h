// Source exposure: binary-analysis
// Static1b640, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b640;
extern void construct(Static1b640*, const Descriptor*);
extern void destroy(Static1b640*);
struct Static1b640 {
    void* value;
    Static1b640() { construct(this, &descriptor); }
    ~Static1b640() { destroy(this); }
};
