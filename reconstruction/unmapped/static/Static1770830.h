// Source exposure: binary-analysis; no external implementation source reused.
// Static1770830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770830*);
    virtual void release(Static1770830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770830*);
struct Static1770830 {
    void* value;
    Static1770830();
    ~Static1770830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
