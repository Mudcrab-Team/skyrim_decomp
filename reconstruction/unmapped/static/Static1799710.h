// Source exposure: binary-analysis; no external implementation source reused.
// Static1799710, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1799710;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1799710*);
    virtual void release(Static1799710*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1799710*);
struct Static1799710 {
    void* value;
    Static1799710();
    ~Static1799710() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
