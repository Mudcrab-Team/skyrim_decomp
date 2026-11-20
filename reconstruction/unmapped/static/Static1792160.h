// Source exposure: binary-analysis; no external implementation source reused.
// Static1792160, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1792160;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1792160*);
    virtual void release(Static1792160*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1792160*);
struct Static1792160 {
    void* value;
    Static1792160();
    ~Static1792160() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
