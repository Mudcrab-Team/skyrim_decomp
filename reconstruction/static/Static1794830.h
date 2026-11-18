// Source exposure: binary-analysis; no external implementation source reused.
// Static1794830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1794830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1794830*);
    virtual void release(Static1794830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1794830*);
struct Static1794830 {
    void* value;
    Static1794830();
    ~Static1794830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
