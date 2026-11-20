// Source exposure: binary-analysis; no external implementation source reused.
// Static175db90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175db90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175db90*);
    virtual void release(Static175db90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175db90*);
struct Static175db90 {
    void* value;
    Static175db90();
    ~Static175db90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
