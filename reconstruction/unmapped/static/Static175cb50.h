// Source exposure: binary-analysis; no external implementation source reused.
// Static175cb50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175cb50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175cb50*);
    virtual void release(Static175cb50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175cb50*);
struct Static175cb50 {
    void* value;
    Static175cb50();
    ~Static175cb50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
