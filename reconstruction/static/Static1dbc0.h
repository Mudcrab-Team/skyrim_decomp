// Source exposure: binary-analysis
// Static1dbc0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1dbc0;
extern void construct(Static1dbc0*, const Descriptor*);
extern void destroy(Static1dbc0*);
struct Static1dbc0 {
    void* value;
    Static1dbc0() { construct(this, &descriptor); }
    ~Static1dbc0() { destroy(this); }
};
