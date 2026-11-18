// Source exposure: binary-analysis; no external implementation source reused.
// Static177b820, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177b820;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177b820*);
    virtual void release(Static177b820*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177b820*);
struct Static177b820 {
    void* value;
    Static177b820();
    ~Static177b820() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
