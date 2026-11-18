// Source exposure: binary-analysis; no external implementation source reused.
// Static175fda0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175fda0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175fda0*);
    virtual void release(Static175fda0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175fda0*);
struct Static175fda0 {
    void* value;
    Static175fda0();
    ~Static175fda0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
