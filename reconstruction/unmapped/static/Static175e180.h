// Source exposure: binary-analysis; no external implementation source reused.
// Static175e180, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e180;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e180*);
    virtual void release(Static175e180*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e180*);
struct Static175e180 {
    void* value;
    Static175e180();
    ~Static175e180() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
