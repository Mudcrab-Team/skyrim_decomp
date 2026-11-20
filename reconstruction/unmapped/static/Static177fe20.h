// Source exposure: binary-analysis; no external implementation source reused.
// Static177fe20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177fe20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177fe20*);
    virtual void release(Static177fe20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177fe20*);
struct Static177fe20 {
    void* value;
    Static177fe20();
    ~Static177fe20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
