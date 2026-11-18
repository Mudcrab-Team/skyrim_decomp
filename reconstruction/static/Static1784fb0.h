// Source exposure: binary-analysis; no external implementation source reused.
// Static1784fb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784fb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784fb0*);
    virtual void release(Static1784fb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784fb0*);
struct Static1784fb0 {
    void* value;
    Static1784fb0();
    ~Static1784fb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
