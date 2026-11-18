// Source exposure: binary-analysis; no external implementation source reused.
// Static175e950, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e950;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e950*);
    virtual void release(Static175e950*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e950*);
struct Static175e950 {
    void* value;
    Static175e950();
    ~Static175e950() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
