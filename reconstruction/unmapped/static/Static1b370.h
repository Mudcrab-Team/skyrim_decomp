// Source exposure: binary-analysis
// Static1b370, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b370;
extern void construct(Static1b370*, const Descriptor*);
extern void destroy(Static1b370*);
struct Static1b370 {
    void* value;
    Static1b370() { construct(this, &descriptor); }
    ~Static1b370() { destroy(this); }
};
