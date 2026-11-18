// Source exposure: binary-analysis; no external implementation source reused.
// Static1756ed0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756ed0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756ed0*);
    virtual void release(Static1756ed0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756ed0*);
struct Static1756ed0 {
    void* value;
    Static1756ed0();
    ~Static1756ed0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
