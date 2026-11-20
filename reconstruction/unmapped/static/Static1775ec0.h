// Source exposure: binary-analysis; no external implementation source reused.
// Static1775ec0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775ec0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775ec0*);
    virtual void release(Static1775ec0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775ec0*);
struct Static1775ec0 {
    void* value;
    Static1775ec0();
    ~Static1775ec0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
