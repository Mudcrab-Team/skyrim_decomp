// Source exposure: binary-analysis; no external implementation source reused.
// Static175afd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175afd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175afd0*);
    virtual void release(Static175afd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175afd0*);
struct Static175afd0 {
    void* value;
    Static175afd0();
    ~Static175afd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
