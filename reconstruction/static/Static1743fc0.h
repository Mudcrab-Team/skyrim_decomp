// Source exposure: binary-analysis; no external implementation source reused.
// Static1743fc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743fc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743fc0*);
    virtual void release(Static1743fc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743fc0*);
struct Static1743fc0 {
    void* value;
    Static1743fc0();
    ~Static1743fc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
