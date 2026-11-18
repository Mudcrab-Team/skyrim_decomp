// Source exposure: binary-analysis; no external implementation source reused.
// Static176c690, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c690;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c690*);
    virtual void release(Static176c690*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c690*);
struct Static176c690 {
    void* value;
    Static176c690();
    ~Static176c690() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
