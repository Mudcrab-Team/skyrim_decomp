// Source exposure: binary-analysis; no external implementation source reused.
// Static176ee90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ee90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ee90*);
    virtual void release(Static176ee90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ee90*);
struct Static176ee90 {
    void* value;
    Static176ee90();
    ~Static176ee90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
