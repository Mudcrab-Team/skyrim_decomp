// Source exposure: binary-analysis; no external implementation source reused.
// Static17b4830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b4830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b4830*);
    virtual void release(Static17b4830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b4830*);
struct Static17b4830 {
    void* value;
    Static17b4830();
    ~Static17b4830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
