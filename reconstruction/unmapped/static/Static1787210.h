// Source exposure: binary-analysis; no external implementation source reused.
// Static1787210, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1787210;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1787210*);
    virtual void release(Static1787210*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1787210*);
struct Static1787210 {
    void* value;
    Static1787210();
    ~Static1787210() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
