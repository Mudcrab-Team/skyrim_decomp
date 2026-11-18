// Source exposure: binary-analysis; no external implementation source reused.
// Static175d550, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d550;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d550*);
    virtual void release(Static175d550*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d550*);
struct Static175d550 {
    void* value;
    Static175d550();
    ~Static175d550() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
