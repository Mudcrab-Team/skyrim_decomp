// Source exposure: binary-analysis; no external implementation source reused.
// Static175df50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175df50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175df50*);
    virtual void release(Static175df50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175df50*);
struct Static175df50 {
    void* value;
    Static175df50();
    ~Static175df50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
