// Source exposure: binary-analysis; no external implementation source reused.
// Static1780b40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1780b40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1780b40*);
    virtual void release(Static1780b40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1780b40*);
struct Static1780b40 {
    void* value;
    Static1780b40();
    ~Static1780b40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
