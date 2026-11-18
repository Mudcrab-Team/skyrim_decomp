// Source exposure: binary-analysis; no external implementation source reused.
// Static175fd00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175fd00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175fd00*);
    virtual void release(Static175fd00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175fd00*);
struct Static175fd00 {
    void* value;
    Static175fd00();
    ~Static175fd00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
