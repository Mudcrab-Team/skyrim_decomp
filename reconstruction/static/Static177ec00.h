// Source exposure: binary-analysis; no external implementation source reused.
// Static177ec00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ec00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ec00*);
    virtual void release(Static177ec00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ec00*);
struct Static177ec00 {
    void* value;
    Static177ec00();
    ~Static177ec00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
