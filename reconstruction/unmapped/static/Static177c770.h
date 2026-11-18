// Source exposure: binary-analysis; no external implementation source reused.
// Static177c770, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c770;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c770*);
    virtual void release(Static177c770*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c770*);
struct Static177c770 {
    void* value;
    Static177c770();
    ~Static177c770() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
