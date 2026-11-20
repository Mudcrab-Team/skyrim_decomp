// Source exposure: binary-analysis; no external implementation source reused.
// Static1787760, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1787760;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1787760*);
    virtual void release(Static1787760*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1787760*);
struct Static1787760 {
    void* value;
    Static1787760();
    ~Static1787760() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
