// Source exposure: binary-analysis; no external implementation source reused.
// Static179f210, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179f210;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179f210*);
    virtual void release(Static179f210*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179f210*);
struct Static179f210 {
    void* value;
    Static179f210();
    ~Static179f210() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
