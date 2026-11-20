// Source exposure: binary-analysis; no external implementation source reused.
// Static1741830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1741830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1741830*);
    virtual void release(Static1741830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1741830*);
struct Static1741830 {
    void* value;
    Static1741830();
    ~Static1741830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
