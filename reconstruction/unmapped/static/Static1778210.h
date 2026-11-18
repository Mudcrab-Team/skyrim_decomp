// Source exposure: binary-analysis; no external implementation source reused.
// Static1778210, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778210;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778210*);
    virtual void release(Static1778210*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778210*);
struct Static1778210 {
    void* value;
    Static1778210();
    ~Static1778210() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
