// Source exposure: binary-analysis; no external implementation source reused.
// Static1762b40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1762b40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1762b40*);
    virtual void release(Static1762b40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1762b40*);
struct Static1762b40 {
    void* value;
    Static1762b40();
    ~Static1762b40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
