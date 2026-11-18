// Source exposure: binary-analysis; no external implementation source reused.
// Static177a830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177a830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177a830*);
    virtual void release(Static177a830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177a830*);
struct Static177a830 {
    void* value;
    Static177a830();
    ~Static177a830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
