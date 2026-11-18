// Source exposure: binary-analysis; no external implementation source reused.
// Static1770fb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770fb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770fb0*);
    virtual void release(Static1770fb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770fb0*);
struct Static1770fb0 {
    void* value;
    Static1770fb0();
    ~Static1770fb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
