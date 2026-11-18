// Source exposure: binary-analysis; no external implementation source reused.
// Static174d3f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174d3f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174d3f0*);
    virtual void release(Static174d3f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174d3f0*);
struct Static174d3f0 {
    void* value;
    Static174d3f0();
    ~Static174d3f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
