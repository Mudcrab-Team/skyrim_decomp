// Source exposure: binary-analysis; no external implementation source reused.
// Static17b4880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b4880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b4880*);
    virtual void release(Static17b4880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b4880*);
struct Static17b4880 {
    void* value;
    Static17b4880();
    ~Static17b4880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
