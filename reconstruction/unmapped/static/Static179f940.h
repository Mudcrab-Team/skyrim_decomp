// Source exposure: binary-analysis; no external implementation source reused.
// Static179f940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179f940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179f940*);
    virtual void release(Static179f940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179f940*);
struct Static179f940 {
    void* value;
    Static179f940();
    ~Static179f940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
