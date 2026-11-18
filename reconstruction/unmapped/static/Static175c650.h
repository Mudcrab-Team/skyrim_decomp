// Source exposure: binary-analysis; no external implementation source reused.
// Static175c650, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175c650;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175c650*);
    virtual void release(Static175c650*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175c650*);
struct Static175c650 {
    void* value;
    Static175c650();
    ~Static175c650() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
