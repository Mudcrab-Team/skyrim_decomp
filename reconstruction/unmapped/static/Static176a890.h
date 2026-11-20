// Source exposure: binary-analysis; no external implementation source reused.
// Static176a890, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a890;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a890*);
    virtual void release(Static176a890*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a890*);
struct Static176a890 {
    void* value;
    Static176a890();
    ~Static176a890() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
