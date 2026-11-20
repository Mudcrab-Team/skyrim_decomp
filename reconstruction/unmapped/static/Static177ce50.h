// Source exposure: binary-analysis; no external implementation source reused.
// Static177ce50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ce50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ce50*);
    virtual void release(Static177ce50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ce50*);
struct Static177ce50 {
    void* value;
    Static177ce50();
    ~Static177ce50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
