// Source exposure: binary-analysis; no external implementation source reused.
// Static1754ae0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754ae0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754ae0*);
    virtual void release(Static1754ae0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754ae0*);
struct Static1754ae0 {
    void* value;
    Static1754ae0();
    ~Static1754ae0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
