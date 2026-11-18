// Source exposure: binary-analysis; no external implementation source reused.
// Static1744830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744830*);
    virtual void release(Static1744830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744830*);
struct Static1744830 {
    void* value;
    Static1744830();
    ~Static1744830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
