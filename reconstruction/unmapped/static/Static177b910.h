// Source exposure: binary-analysis; no external implementation source reused.
// Static177b910, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177b910;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177b910*);
    virtual void release(Static177b910*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177b910*);
struct Static177b910 {
    void* value;
    Static177b910();
    ~Static177b910() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
