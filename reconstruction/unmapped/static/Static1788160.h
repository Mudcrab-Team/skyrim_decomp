// Source exposure: binary-analysis; no external implementation source reused.
// Static1788160, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1788160;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1788160*);
    virtual void release(Static1788160*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1788160*);
struct Static1788160 {
    void* value;
    Static1788160();
    ~Static1788160() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
