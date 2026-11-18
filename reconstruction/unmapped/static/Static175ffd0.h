// Source exposure: binary-analysis; no external implementation source reused.
// Static175ffd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ffd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ffd0*);
    virtual void release(Static175ffd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ffd0*);
struct Static175ffd0 {
    void* value;
    Static175ffd0();
    ~Static175ffd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
