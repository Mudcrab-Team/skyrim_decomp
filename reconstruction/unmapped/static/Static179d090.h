// Source exposure: binary-analysis; no external implementation source reused.
// Static179d090, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179d090;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179d090*);
    virtual void release(Static179d090*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179d090*);
struct Static179d090 {
    void* value;
    Static179d090();
    ~Static179d090() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
