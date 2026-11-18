// Source exposure: binary-analysis; no external implementation source reused.
// Static1753e60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753e60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753e60*);
    virtual void release(Static1753e60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753e60*);
struct Static1753e60 {
    void* value;
    Static1753e60();
    ~Static1753e60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
