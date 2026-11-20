// Source exposure: binary-analysis; no external implementation source reused.
// Static175ef90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ef90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ef90*);
    virtual void release(Static175ef90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ef90*);
struct Static175ef90 {
    void* value;
    Static175ef90();
    ~Static175ef90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
