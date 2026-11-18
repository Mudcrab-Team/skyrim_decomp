// Source exposure: binary-analysis; no external implementation source reused.
// Static1789670, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1789670;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1789670*);
    virtual void release(Static1789670*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1789670*);
struct Static1789670 {
    void* value;
    Static1789670();
    ~Static1789670() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
