// Source exposure: binary-analysis; no external implementation source reused.
// Static175fbc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175fbc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175fbc0*);
    virtual void release(Static175fbc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175fbc0*);
struct Static175fbc0 {
    void* value;
    Static175fbc0();
    ~Static175fbc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
