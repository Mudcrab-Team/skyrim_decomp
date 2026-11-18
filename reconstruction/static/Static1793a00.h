// Source exposure: binary-analysis; no external implementation source reused.
// Static1793a00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1793a00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1793a00*);
    virtual void release(Static1793a00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1793a00*);
struct Static1793a00 {
    void* value;
    Static1793a00();
    ~Static1793a00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
