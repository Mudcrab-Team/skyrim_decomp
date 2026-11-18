// Source exposure: binary-analysis; no external implementation source reused.
// Static1787350, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1787350;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1787350*);
    virtual void release(Static1787350*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1787350*);
struct Static1787350 {
    void* value;
    Static1787350();
    ~Static1787350() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
