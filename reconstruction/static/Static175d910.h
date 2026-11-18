// Source exposure: binary-analysis; no external implementation source reused.
// Static175d910, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d910;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d910*);
    virtual void release(Static175d910*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d910*);
struct Static175d910 {
    void* value;
    Static175d910();
    ~Static175d910() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
