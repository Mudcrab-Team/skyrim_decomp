// Source exposure: binary-analysis; no external implementation source reused.
// Static175aa80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175aa80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175aa80*);
    virtual void release(Static175aa80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175aa80*);
struct Static175aa80 {
    void* value;
    Static175aa80();
    ~Static175aa80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
