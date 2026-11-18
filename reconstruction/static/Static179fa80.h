// Source exposure: binary-analysis; no external implementation source reused.
// Static179fa80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179fa80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179fa80*);
    virtual void release(Static179fa80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179fa80*);
struct Static179fa80 {
    void* value;
    Static179fa80();
    ~Static179fa80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
