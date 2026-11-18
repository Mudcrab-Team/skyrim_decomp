// Source exposure: binary-analysis; no external implementation source reused.
// Static176d770, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d770;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d770*);
    virtual void release(Static176d770*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d770*);
struct Static176d770 {
    void* value;
    Static176d770();
    ~Static176d770() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
