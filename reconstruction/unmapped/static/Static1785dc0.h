// Source exposure: binary-analysis; no external implementation source reused.
// Static1785dc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785dc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785dc0*);
    virtual void release(Static1785dc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785dc0*);
struct Static1785dc0 {
    void* value;
    Static1785dc0();
    ~Static1785dc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
