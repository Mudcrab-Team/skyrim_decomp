// Source exposure: binary-analysis; no external implementation source reused.
// Static1778300, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778300;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778300*);
    virtual void release(Static1778300*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778300*);
struct Static1778300 {
    void* value;
    Static1778300();
    ~Static1778300() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
