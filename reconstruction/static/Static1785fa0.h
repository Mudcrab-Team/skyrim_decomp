// Source exposure: binary-analysis; no external implementation source reused.
// Static1785fa0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785fa0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785fa0*);
    virtual void release(Static1785fa0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785fa0*);
struct Static1785fa0 {
    void* value;
    Static1785fa0();
    ~Static1785fa0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
