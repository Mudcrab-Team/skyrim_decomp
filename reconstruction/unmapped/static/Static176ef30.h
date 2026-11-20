// Source exposure: binary-analysis; no external implementation source reused.
// Static176ef30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ef30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ef30*);
    virtual void release(Static176ef30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ef30*);
struct Static176ef30 {
    void* value;
    Static176ef30();
    ~Static176ef30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
