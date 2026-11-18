// Source exposure: binary-analysis; no external implementation source reused.
// Static179e480, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179e480;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179e480*);
    virtual void release(Static179e480*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179e480*);
struct Static179e480 {
    void* value;
    Static179e480();
    ~Static179e480() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
