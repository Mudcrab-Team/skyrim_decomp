// Source exposure: binary-analysis
// Static80560, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static80560;
extern void construct(Static80560*, const Descriptor*);
extern void destroy(Static80560*);
struct Static80560 {
    void* value;
    Static80560() { construct(this, &descriptor); }
    ~Static80560() { destroy(this); }
};
