// Source exposure: binary-analysis; no external implementation source reused.
// Static175e090, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e090;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e090*);
    virtual void release(Static175e090*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e090*);
struct Static175e090 {
    void* value;
    Static175e090();
    ~Static175e090() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
