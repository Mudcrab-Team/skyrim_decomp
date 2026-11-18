// Source exposure: binary-analysis; no external implementation source reused.
// Static176c230, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c230;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c230*);
    virtual void release(Static176c230*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c230*);
struct Static176c230 {
    void* value;
    Static176c230();
    ~Static176c230() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
