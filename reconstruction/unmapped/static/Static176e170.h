// Source exposure: binary-analysis; no external implementation source reused.
// Static176e170, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e170;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e170*);
    virtual void release(Static176e170*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e170*);
struct Static176e170 {
    void* value;
    Static176e170();
    ~Static176e170() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
