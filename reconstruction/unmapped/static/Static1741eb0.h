// Source exposure: binary-analysis; no external implementation source reused.
// Static1741eb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1741eb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1741eb0*);
    virtual void release(Static1741eb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1741eb0*);
struct Static1741eb0 {
    void* value;
    Static1741eb0();
    ~Static1741eb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
