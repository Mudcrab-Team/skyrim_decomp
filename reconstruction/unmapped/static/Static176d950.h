// Source exposure: binary-analysis; no external implementation source reused.
// Static176d950, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d950;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d950*);
    virtual void release(Static176d950*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d950*);
struct Static176d950 {
    void* value;
    Static176d950();
    ~Static176d950() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
