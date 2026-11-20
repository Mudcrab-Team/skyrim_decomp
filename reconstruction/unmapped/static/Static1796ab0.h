// Source exposure: binary-analysis; no external implementation source reused.
// Static1796ab0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1796ab0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1796ab0*);
    virtual void release(Static1796ab0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1796ab0*);
struct Static1796ab0 {
    void* value;
    Static1796ab0();
    ~Static1796ab0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
