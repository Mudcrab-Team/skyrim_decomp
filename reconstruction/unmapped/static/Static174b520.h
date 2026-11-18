// Source exposure: binary-analysis; no external implementation source reused.
// Static174b520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174b520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174b520*);
    virtual void release(Static174b520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174b520*);
struct Static174b520 {
    void* value;
    Static174b520();
    ~Static174b520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
