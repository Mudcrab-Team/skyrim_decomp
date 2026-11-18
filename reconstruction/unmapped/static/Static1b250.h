// Source exposure: binary-analysis
// Static1b250, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b250;
extern void construct(Static1b250*, const Descriptor*);
extern void destroy(Static1b250*);
struct Static1b250 {
    void* value;
    Static1b250() { construct(this, &descriptor); }
    ~Static1b250() { destroy(this); }
};
