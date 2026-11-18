// Source exposure: binary-analysis; no external implementation source reused.
// Static176d090, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d090;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d090*);
    virtual void release(Static176d090*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d090*);
struct Static176d090 {
    void* value;
    Static176d090();
    ~Static176d090() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
