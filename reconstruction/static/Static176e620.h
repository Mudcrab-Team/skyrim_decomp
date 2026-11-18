// Source exposure: binary-analysis; no external implementation source reused.
// Static176e620, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e620;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e620*);
    virtual void release(Static176e620*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e620*);
struct Static176e620 {
    void* value;
    Static176e620();
    ~Static176e620() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
