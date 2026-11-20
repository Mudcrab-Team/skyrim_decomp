// Source exposure: binary-analysis; no external implementation source reused.
// Static174c230, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174c230;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174c230*);
    virtual void release(Static174c230*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174c230*);
struct Static174c230 {
    void* value;
    Static174c230();
    ~Static174c230() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
