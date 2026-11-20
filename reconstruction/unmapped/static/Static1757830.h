// Source exposure: binary-analysis; no external implementation source reused.
// Static1757830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757830*);
    virtual void release(Static1757830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757830*);
struct Static1757830 {
    void* value;
    Static1757830();
    ~Static1757830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
