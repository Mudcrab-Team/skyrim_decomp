// Source exposure: binary-analysis; no external implementation source reused.
// Static1778ee0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778ee0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778ee0*);
    virtual void release(Static1778ee0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778ee0*);
struct Static1778ee0 {
    void* value;
    Static1778ee0();
    ~Static1778ee0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
