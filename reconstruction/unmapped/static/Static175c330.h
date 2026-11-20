// Source exposure: binary-analysis; no external implementation source reused.
// Static175c330, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175c330;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175c330*);
    virtual void release(Static175c330*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175c330*);
struct Static175c330 {
    void* value;
    Static175c330();
    ~Static175c330() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
