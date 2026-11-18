// Source exposure: binary-analysis; no external implementation source reused.
// Static1748830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1748830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1748830*);
    virtual void release(Static1748830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1748830*);
struct Static1748830 {
    void* value;
    Static1748830();
    ~Static1748830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
