// Source exposure: binary-analysis; no external implementation source reused.
// Static174d490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174d490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174d490*);
    virtual void release(Static174d490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174d490*);
struct Static174d490 {
    void* value;
    Static174d490();
    ~Static174d490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
