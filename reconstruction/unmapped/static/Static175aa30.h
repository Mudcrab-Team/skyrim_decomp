// Source exposure: binary-analysis; no external implementation source reused.
// Static175aa30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175aa30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175aa30*);
    virtual void release(Static175aa30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175aa30*);
struct Static175aa30 {
    void* value;
    Static175aa30();
    ~Static175aa30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
