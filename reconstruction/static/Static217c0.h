// Source exposure: binary-analysis
// Static217c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static217c0;
extern void construct(Static217c0*, const Descriptor*);
extern void destroy(Static217c0*);
struct Static217c0 {
    void* value;
    Static217c0() { construct(this, &descriptor); }
    ~Static217c0() { destroy(this); }
};
