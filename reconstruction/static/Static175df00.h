// Source exposure: binary-analysis; no external implementation source reused.
// Static175df00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175df00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175df00*);
    virtual void release(Static175df00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175df00*);
struct Static175df00 {
    void* value;
    Static175df00();
    ~Static175df00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
