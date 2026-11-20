// Source exposure: binary-analysis
// Static103370, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static103370;
extern void construct(Static103370*, const Descriptor*);
extern void destroy(Static103370*);
struct Static103370 {
    void* value;
    Static103370() { construct(this, &descriptor); }
    ~Static103370() { destroy(this); }
};
