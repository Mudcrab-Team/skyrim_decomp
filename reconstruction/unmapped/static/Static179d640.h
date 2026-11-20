// Source exposure: binary-analysis; no external implementation source reused.
// Static179d640, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179d640;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179d640*);
    virtual void release(Static179d640*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179d640*);
struct Static179d640 {
    void* value;
    Static179d640();
    ~Static179d640() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
