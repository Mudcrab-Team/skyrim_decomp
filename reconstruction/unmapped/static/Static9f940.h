// Source exposure: binary-analysis
// Static9f940, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f940;
extern void construct(Static9f940*, const Descriptor*);
extern void destroy(Static9f940*);
struct Static9f940 {
    void* value;
    Static9f940() { construct(this, &descriptor); }
    ~Static9f940() { destroy(this); }
};
