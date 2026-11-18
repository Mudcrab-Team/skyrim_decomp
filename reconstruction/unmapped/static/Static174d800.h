// Source exposure: binary-analysis; no external implementation source reused.
// Static174d800, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174d800;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174d800*);
    virtual void release(Static174d800*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174d800*);
struct Static174d800 {
    void* value;
    Static174d800();
    ~Static174d800() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
