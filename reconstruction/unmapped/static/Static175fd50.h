// Source exposure: binary-analysis; no external implementation source reused.
// Static175fd50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175fd50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175fd50*);
    virtual void release(Static175fd50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175fd50*);
struct Static175fd50 {
    void* value;
    Static175fd50();
    ~Static175fd50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
