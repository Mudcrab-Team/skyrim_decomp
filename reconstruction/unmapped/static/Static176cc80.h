// Source exposure: binary-analysis; no external implementation source reused.
// Static176cc80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176cc80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176cc80*);
    virtual void release(Static176cc80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176cc80*);
struct Static176cc80 {
    void* value;
    Static176cc80();
    ~Static176cc80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
