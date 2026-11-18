// Source exposure: binary-analysis; no external implementation source reused.
// Static175c790, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175c790;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175c790*);
    virtual void release(Static175c790*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175c790*);
struct Static175c790 {
    void* value;
    Static175c790();
    ~Static175c790() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
