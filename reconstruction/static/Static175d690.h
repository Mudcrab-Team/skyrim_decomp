// Source exposure: binary-analysis; no external implementation source reused.
// Static175d690, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d690;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d690*);
    virtual void release(Static175d690*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d690*);
struct Static175d690 {
    void* value;
    Static175d690();
    ~Static175d690() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
