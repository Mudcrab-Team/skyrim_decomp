// Source exposure: binary-analysis; no external implementation source reused.
// Static1794cf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1794cf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1794cf0*);
    virtual void release(Static1794cf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1794cf0*);
struct Static1794cf0 {
    void* value;
    Static1794cf0();
    ~Static1794cf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
