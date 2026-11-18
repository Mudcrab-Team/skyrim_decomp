// Source exposure: binary-analysis; no external implementation source reused.
// Static1778760, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778760;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778760*);
    virtual void release(Static1778760*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778760*);
struct Static1778760 {
    void* value;
    Static1778760();
    ~Static1778760() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
