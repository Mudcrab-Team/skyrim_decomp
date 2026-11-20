// Source exposure: binary-analysis
// Static24410, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static24410;
extern void construct(Static24410*, const Descriptor*);
extern void destroy(Static24410*);
struct Static24410 {
    void* value;
    Static24410() { construct(this, &descriptor); }
    ~Static24410() { destroy(this); }
};
