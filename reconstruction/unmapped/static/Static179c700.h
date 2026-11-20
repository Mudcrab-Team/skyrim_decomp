// Source exposure: binary-analysis; no external implementation source reused.
// Static179c700, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179c700;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179c700*);
    virtual void release(Static179c700*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179c700*);
struct Static179c700 {
    void* value;
    Static179c700();
    ~Static179c700() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
