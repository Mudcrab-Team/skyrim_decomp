// Source exposure: binary-analysis; no external implementation source reused.
// Static1741ab0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1741ab0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1741ab0*);
    virtual void release(Static1741ab0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1741ab0*);
struct Static1741ab0 {
    void* value;
    Static1741ab0();
    ~Static1741ab0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
